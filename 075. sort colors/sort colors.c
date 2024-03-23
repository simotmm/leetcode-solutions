// https://leetcode.com/problems/sort-colors/description/

//count sort
int countNumber(int *v, int n, int x){
    int i, cont=0;
    for(i=0;i<n;i++)
        if(v[i]==x) 
            cont++;
    return cont;
}

void colorSort(int *v, int n){
    int i, zeroes=countNumber(v, n, 0);
    int ones=countNumber(v, n, 1);
    int twos=countNumber(v, n, 2);

    for(i=0;i<n;i++)
        if(i>=0 && i<zeroes)
            v[i]=0;
        else if(i>=zeroes && i<zeroes+ones)
            v[i]=1;
        else 
            v[i]=2;
}

void sortColors(int* nums, int numsSize){
    colorSort(nums, numsSize);
}

/*
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
    while(i<n1 && j<n2){
        if(vl[i]<=vr[j])
            v[k]=vl[i++];
        else
            v[k]=vr[j++];
        k++;
    }

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

void sortColors(int* nums, int numsSize) {
    mergeSort(nums, 0, --numsSize);
}
*/