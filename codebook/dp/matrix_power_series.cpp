// 這是使用費式數列的矩陣快速冪為例的模板
typedef array<array<int,2>,2> Matrix;
Matrix operator*(Matrix A , Matrix B){
    Matrix C;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j]=0;
            for(int k=0;k<2;k++)
                C[i][j]=(C[i][j]%m+(A[i][k]%m*B[k][j]%m)%m)%m;
        }
    }
    return C;
}
Matrix power(Matrix A,int n){
    Matrix ans={{{1,0},{0,1}}};
    while(n){
        if(n&1)
            ans=ans*A;
        n>>=1;
        A=A*A;
    }
    return ans;
}
// Matrix A={{{1,1},{1,0}}};
// Matrix C=power(A,num-1);
// Answer: C[0][0]