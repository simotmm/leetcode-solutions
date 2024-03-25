// https://leetcode.com/problems/perfect-number/


// da rifare
bool checkPerfectNumber(int num) {
    if(num<=1) return 0;
    int x=num, div=1, sum=0;
    while(div<=num/2){
        if(num%div==0)
            sum+=div;
        div++;
    }
    return sum==num;
}