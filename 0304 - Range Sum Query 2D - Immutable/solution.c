typedef struct {
    int **dp, m, n;    
} NumMatrix;

NumMatrix* numMatrixCreate(int** A, int sz, int* colSz) {
    NumMatrix *res = (NumMatrix*)malloc(sizeof(NumMatrix));
    res->m = sz, res->n = colSz[0];
    res->dp = (int**)malloc((res->m+1)*sizeof(int*));
    for(int i = 0; i <= res->m; i++){
        res->dp[i] = (int*)malloc((res->n+1)*sizeof(int));
        for(int j = 0; j <= res->n; j++){
            if(i==0 || j==0) res->dp[i][j] = 0;
            else res->dp[i][j] = res->dp[i-1][j]+res->dp[i][j-1]-res->dp[i-1][j-1]+A[i-1][j-1];
        }
    }
    return res;
}

int numMatrixSumRegion(NumMatrix* obj, int r1, int c1, int r2, int c2) {
    return obj->dp[r2+1][c2+1]-obj->dp[r2+1][c1]-obj->dp[r1][c2+1]+obj->dp[r1][c1];
}

void numMatrixFree(NumMatrix* obj) {
    for(int i = 0; i <= obj->m; i++) free(obj->dp[i]);
    free(obj->dp);
}

/**
 * Your NumMatrix struct will be instantiated and called as such:
 * NumMatrix* obj = numMatrixCreate(matrix, matrixSize, matrixColSize);
 * int param_1 = numMatrixSumRegion(obj, row1, col1, row2, col2);
 
 * numMatrixFree(obj);
*/