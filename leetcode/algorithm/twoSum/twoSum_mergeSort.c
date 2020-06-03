struct node
{
    int val;
    int pos;
};

void merge(struct node *a, int first, int medium, int end);
void mergeSort(struct node *arr, int first, int end);

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    struct node *arrNode = (struct node *)malloc(numsSize*sizeof(struct node));
    int *res = (int *)malloc(2*sizeof(int));
    *returnSize = 2;

    for(int i = 0; i < numsSize; i++)
    {
        arrNode[i].val = nums[i];
        arrNode[i].pos = i;
    }

    mergeSort(arrNode, 0, numsSize-1);

    int first = 0;
    int second = numsSize - 1;
    while(first < second)
    {
        if(arrNode[first].val + arrNode[second].val == target)
        {
            res[0] = arrNode[first].pos;
            res[1] = arrNode[second].pos;
            break;
        }
        else if(arrNode[first].val + arrNode[second].val > target)
        {
            second--;
        }
        else
        {
            first++;
        }
    }
    free(arrNode);
    return res;
}

void mergeSort(struct node *arr, int first, int end) {
	if (first < end) {
		int medium = (first + end) / 2;
		mergeSort(arr, first, medium);
		mergeSort(arr, medium + 1, end);
		merge(arr, first, medium, end);
	}
}

void merge(struct node *a, int first, int medium, int end) {
	int n1 = medium - first + 1;
	int n2 = end - medium;
	struct node *b = (struct node *)malloc(n1*sizeof(struct node));
	struct node *c = (struct node *)malloc(n2*sizeof(struct node));
	int i, j, k;

	// 将当前要归并的数组分别赋值，暂存
	for (i = 0, k = first; i < n1; i++, k++) {
		b[i].pos = a[k].pos;
        b[i].val = a[k].val;
	}
	for (i = 0, k = medium + 1; i < n2; i++, k++) {
		c[i].pos = a[k].pos;
        c[i].val = a[k].val;
	}

	// 将最小的项填进原数组
	for (i = 0, j = 0, k = first; i < n1 && j < n2; k++) {
		if (b[i].val < c[j].val) {
			a[k].val = b[i].val;
            a[k].pos = b[i].pos;
			i++;
		}
		else {
			a[k].val = c[j].val;
            a[k].pos = c[j].pos;
			j++;
		}
	}

	// 判断b, c是哪个数组还未被完全排序
	if (i < n1) {
		for (int m = i; m < n1; m++) {
			a[k].val = b[m].val;
            a[k].pos = b[m].pos;
			k++;
		}
	}
	if (j < n2) {
		for (int m = j; m < n2; m++) {
			a[k].val = c[m].val;
            a[k].pos = c[m].pos;
            k++;
		}
	}
    free(b);
    free(c);
}