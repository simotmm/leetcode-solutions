// https://leetcode.com/problems/palindrome-number

#include <string.h>

bool isPalindrome(int x) {
    char n[1000];
    sprintf(n, "%d", x);
    int l, r;
    for(l=0, r=strlen(n)-1;l<=r;l++, r--)
        if(n[l]!=n[r])
            return 0;
    return 1;
}