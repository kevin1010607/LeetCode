#define INF 0x3f3f3f3f
#define min(a,b) (((a)<(b))?(a):(b))
void cmp(int i, int j, int k, int dp[][101][21], int minN[][101][2], int minIdx[][101]){
    if(dp[i][j][k] < minN[i][j][0])
        minN[i][j][1] = minN[i][j][0], minN[i][j][0] = dp[i][j][k], minIdx[i][j] = k;
    else if(dp[i][j][k] < minN[i][j][1])
        minN[i][j][1] = dp[i][j][k];
}
int minCost(int* A, int ASz, int** cost, int costSz, int* costColSz, int m, int n, int target){
    int dp[100][101][21], minN[100][101][2], minIdx[100][101];
    memset(dp, 0x3f, 100*101*21*sizeof(int));
    memset(minN, 0x3f, 100*101*2*sizeof(int));
    memset(minIdx, 0x3f, 100*101*sizeof(int));
    for(int k = 1; k <= n; k++){
        if(A[0] == k) dp[0][1][k] = 0;
        else if(!A[0]) dp[0][1][k] = cost[0][k-1];
        cmp(0, 1, k, dp, minN, minIdx);
    }
    for(int i = 1; i < m; i++){
        for(int j = 1; j <= min(target, i+1); j++){
            for(int k = 1; k <= n; k++){
                if(A[i] && A[i]!=k) continue;
                dp[i][j][k] = min(minN[i-1][j-1][k==minIdx[i-1][j-1]], dp[i-1][j][k]);
                if(!A[i]) dp[i][j][k] += cost[i][k-1];
                cmp(i, j, k, dp, minN, minIdx);
            }
        }
    }
    return minN[m-1][target][0]<INF?minN[m-1][target][0]:-1;
}