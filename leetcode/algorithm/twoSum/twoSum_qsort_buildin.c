// must use long int,or index out of bounds
int cmpInt(const void*a,const void*b)
{
    return *(long int*)a-*(long int*)b;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int arrNode[numsSize][2];   // c99 standard
    int *res = (int *)malloc(2*sizeof(int));
    *returnSize = 2;

    int i;
    for(i = 0; i < numsSize; i++)
    {
        arrNode[i][0] = nums[i];
        arrNode[i][1] = i;
    }

    qsort(arrNode[0], numsSize, sizeof(long int), cmpInt);

    int first = 0;
    int second = numsSize - 1;
    while(first < second)
    {
        if(arrNode[first][0] + arrNode[second][0] == target)
        {
            res[0] = arrNode[first][1];
            res[1] = arrNode[second][1];
            break;
        }
        else if(arrNode[first][0] + arrNode[second][0] > target)
        {
            second--;
        }
        else
        {
            first++;
        }
    }
    return res;
}