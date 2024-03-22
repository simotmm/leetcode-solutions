// https://leetcode.com/problems/climbing-stairs

// programmazione dinamica
int climbStairs(int n){
    if(n<=2)            //c: n. di modi per raggiungere lo step corrente
        return n;       //b: n. di modi per raggiungere lo step precedente
    int a=1, b=2, c, i; //a: n. di modi per raggiungere lo step precedente al precedente
    for(i=3;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

/*
// ricorsivo: non va bene -> troppo tempo
void climbR(int n, int i, int *cont){
    printf("i: %d, cont: %d (n: %d)\n", i, *cont, n);
    if(i==n){
        (*cont)++;
        return;
    }
    climbR(n, i+1, cont);
    if(i+2<=n)
        climbR(n, i+2, cont);
}

int climbStairs(int n) {
    int *cont=calloc(1, sizeof(int)), a;
    climbR(n, 0, cont);
    a=*cont;
    free(cont);
    return a;
}
*/