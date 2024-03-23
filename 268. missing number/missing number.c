// https://leetcode.com/problems/missing-number/description/

//time complexity: O(n+n+1)=O(2n+1)~O(n)
int missingNumber(int* nums, int numsSize) {
    int *check=calloc(numsSize+1, sizeof(int)), missing, i;

    for(i=0;i<numsSize;i++)
        check[nums[i]]=1;

    for(i=0;i<=numsSize;i++)
        if(check[i]==0)
            missing=i;

    free(check);
    return missing;
}