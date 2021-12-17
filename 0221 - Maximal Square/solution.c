int min(int a, int b, int c) {return a<(b<c?b:c)?a:(b<c?b:c);}
int max(int a, int b) {return a>b?a:b;}
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize, n = m>0?*matrixColSize:0;
    int *dp = (int*)calloc(n+1, sizeof(int));
    int res = 0, prev = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            int tmp = dp[j];
            dp[j] = matrix[i-1][j-1]=='1'?min(prev, dp[j], dp[j-1])+1:0;
            res = max(res, dp[j]);
            prev = tmp;
        }
    }
    free(dp);
    return res*res;
}