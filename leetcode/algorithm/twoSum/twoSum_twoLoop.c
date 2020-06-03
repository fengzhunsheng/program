int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int i;
    int j;
    int flag = 1;
    int *res = (int *)malloc(2*sizeof(int));
    *returnSize = 2;

    if(nums == NULL) return NULL;

	// 对于双重循环，要直接从内层循环跳出外层循环外，加一个flag标志位
    for(i = 0; i < numsSize && flag; i++)
    {
        for(j = i+1; j < numsSize; j++)
        {
            if(nums[i]+nums[j]==target)
            {
                res[0]=i;
                res[1]=j;
                flag = 0;
                break;
            }
        }
    }

    return res;
}