// https://leetcode.com/problems/rotate-image

void invertiVettore(int *v, int n){
    int i, a;
    for(i=0;i<n/2;i++){
        a=v[i];
        v[i]=v[n-i-1];
        v[n-i-1]=a;
    }
}

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    int i, j, a, n=matrixSize;
    for(i=0;i<matrixSize-1;i++){
        for(j=i+1;j<matrixSize;j++){
            a=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=a;
        }
    }
    for(i=0;i<matrixSize;i++)
        invertiVettore(matrix[i], matrixSize);    
}

/*void stampa(int **m, int r, int c){
    int i, j;
    for(i=0, j=0;i<r;i++)
        for(j=0;j<c;j++)
            printf(" %2d %s%s", m[i][j], j==(c-1)?"\n":"", i==(r-1)&&j==(c-1)?"\n":"");
}*/