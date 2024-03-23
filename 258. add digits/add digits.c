// https://leetcode.com/problems/add-digits

int addDigits(int num) {
    if(num<10)
        return num;
    int sum=0;
    while(num!=0){
        sum+=num%10;
        num/=10;
    }
    return addDigits(sum);
}

/*
int addDigits(int num){
    int res=0, n, m;
    while(1){
        n=num%10;
        if(n==num)
            return num;
        m=num/10;
        res=n+m;
        num=res;
    }
    return num;
}
*/
