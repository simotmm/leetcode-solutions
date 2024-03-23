// https://leetcode.com/problems/median-of-two-sorted-arrays/description/

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int *v=calloc(nums1Size+nums2Size, sizeof(int)), n=nums1Size+nums2Size, i, j=0, k=0;

    for(i=0;i<n;i++)
        if(j<nums1Size && k<nums2Size)
            v[i]=nums1[j]<nums2[k]? nums1[j++] : nums2[k++];
        else if(j<nums1Size && k>=nums2Size)
            v[i]=nums1[j++];
        else
            v[i]=nums2[k++];
  
    return n%2!=0? v[n/2] : (double)(v[n/2]+v[n/2-1])/2;
}
