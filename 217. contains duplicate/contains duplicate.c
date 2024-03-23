// https://leetcode.com/problems/contains-duplicate/description/


// (runtime troppo alto, da rifare)
//merge sort
void merge(int *v, int l, int m, int r){
    int n1=m-l+1, n2=r-m, i, j, k;
    int *vl=calloc(n1, sizeof(int)), *vr=calloc(n2, sizeof(int));

    for(i=0;i<n1;i++)
        vl[i]=v[l+i];

    for(j=0;j<n2;j++)
        vr[j]=v[m+1+j];

    i=0;
    j=i;
    k=l;
    while(i<n1 && j<n2)
        if(vl[i]<=vr[j])
            v[k++]=vl[i++];
        else
            v[k++]=vr[j++];

    while(i<n1)
        v[k++]=vl[i++];

    while(j<n2)
        v[k++]=vr[j++];
        
    free(vr);
    free(vl);
}

void mergeSort(int *v, int l, int r){
    if(l>=r) return;

    int m=l+(r-l)/2;
    mergeSort(v, l, m);
    mergeSort(v, m+1, r);
    merge(v, l, m, r);
}

bool containsDuplicate(int* nums, int numsSize) {
    /*
    // O(n^2) -> non va
    int i, j;
    for(i=0;i<numsSize;i++)
        for(j=i+1;j<numsSize;j++)
            if(nums[i]==nums[j])
                return 1;
    return 0;
    */

    //merge sort
    int i;
    mergeSort(nums, 0, numsSize-1);

    for(i=0;i<numsSize-1;i++)
        if(nums[i]==nums[i+1])
            return 1;
    return 0;
}