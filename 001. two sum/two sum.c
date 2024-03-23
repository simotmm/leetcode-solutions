/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// O(n^2) algorithm, to be implemented with hashmap
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int *res=calloc(2, sizeof(int)), i, j;
    *returnSize=2;

    for(i=0;i<numsSize;i++)
        for(j=i+1;j<numsSize;j++)
            if(nums[i]+nums[j]==target){
                res[0]=i;
                res[1]=j;
                return res;
            }
    
    return res;
}