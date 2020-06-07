/*
 *	题目：
 	给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。
 	找出这两个正序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 	假设 nums1 和 nums2 不会同时为空。
 
 *	示例1：
		nums1 = [1, 3]
		nums2 = [2]

		则中位数是 2.0
		
 *	示例2：
		nums1 = [1, 2]
		nums2 = [3, 4]

		则中位数是 (2 + 3)/2 = 2.5
 */

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double median;

    int flag = 0;
    if((nums1Size + nums2Size) % 2 == 1) flag = 1;

    // k为两个数组中中位数的起始位置（奇数就是第k个，偶数就是第k,k+1个）
    int k = (nums1Size + nums2Size - 1)/2 + 1;
    int cur_idx = k/2 - 1;

    // n1为nums1已经筛掉的数目，n2为nums2已经筛掉的数目
    int n1 = 0;
    int n2 = 0;
    
    // 对于数组每次的每次访问都要检查下标是否越界
    while(cur_idx >= 0)
    {
        // n1,n2记录对应数组中已经筛掉的个数
        if(n1+cur_idx < nums1Size && n2+cur_idx < nums2Size)
        {
            if(nums1[cur_idx + n1] <= nums2[cur_idx + n2])
            {
                n1 += cur_idx + 1;
            }
            else
            {
                n2 += cur_idx + 1;
            }
        }
        else if(n1+cur_idx < nums1Size)
        {
            n1 += cur_idx + 1;
        } 
        else
        {
            n2 += cur_idx + 1;
        }

        // 剔除本次循环已经筛掉的个数，得到还需剔除的个数
        k = k - k/2;
		
		// 计算下一次循环除去n1,n2后应该访问的索引
        cur_idx = k/2 - 1; 
    }
    

    int k0 = 0;
    int k1 = 0;

    if(n1<nums1Size && n2<nums2Size)
    {
        k0 = (nums1[n1]<=nums2[n2]) ? nums1[n1] : nums2[n2];
    }
    else if(n1<nums1Size)
    {
        k0 = nums1[n1];
    }
    else k0 = nums2[n2];

    if(flag == 0)
    {
        if(n1<nums1Size && n2<nums2Size)
        {
            if(k0 == nums1[n1])
            {
                k1 = (n1+1<nums1Size && nums1[n1+1]<=nums2[n2]) ? nums1[n1+1] : nums2[n2];
            }
            else
            {
                k1 = (n2+1<nums2Size && nums2[n2+1]<=nums1[n1]) ? nums2[n2+1] : nums1[n1];
            }
        }
        else if(n1<nums1Size)
        {
            k1 = nums1[n1+1];
        }
        else k1 = nums2[n2+1];

        median = (k0 + k1)/2.0;    
    }
    else median = (double)k0;
    
    
    return median;
}