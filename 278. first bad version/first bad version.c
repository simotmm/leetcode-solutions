// https://leetcode.com/problems/first-bad-version/description/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

#define STUPID 0

int approccioTroll(int n){
    int i;
    for (i=n;i>0;i--) 
        if (!isBadVersion(i)) 
            return i+1;
    return 1;
}

int b(int x){return isBadVersion(x);}

int search(int n, int l, int r){
    if(r<l) return -1;

    int m=l+(r-l)/2;
    if(!b(m-1) && b(m)) return m;
    if(b(m-1) && b(m)) return search(n, l, m-1);
    return search(n, m+1, r);
}

int firstBadVersion(int n) {
    //serve algoritmo < O(n)
    
    #if STUPID
    return approccioTroll(n);
    #endif

    //binary search
    return search(n, 1, n);
}