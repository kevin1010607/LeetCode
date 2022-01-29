#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    int res = 0, m = matrixSize, n = *matrixColSize, dp[205] = {};
    for(int i = 0; i < m; i++){
        int t[205] = {};
        for(int j = 0; j < n; j++) dp[j] = matrix[i][j]=='1'?dp[j]+1:0;
        for(int j = 0; j < n; j++){
            int h = dp[j];
            for(int k = j; k < n; k++){
                h = min(h, dp[k]);
                if(h <= t[k]) break;
                t[k] = h;
                res = max(res, h*(k-j+1));
            }
        }
    }
    return res;
}