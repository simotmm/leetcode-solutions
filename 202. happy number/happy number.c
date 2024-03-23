// https://leetcode.com/problems/happy-number/description/

int sumOfSquareDigits(int x){
    int sum=0;
    while(x>0){
        sum+=(x%10)*(x%10);
        x/=10;
    }
    return sum;
}

int isHappy(int n) {
    if(n==1) return 1;
    if(n==4) return 0;
    return isHappy(sumOfSquareDigits(n));
}