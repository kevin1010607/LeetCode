int kInversePairs(int n, int k){
    int dp[2][1001] = {}, MOD = 1e9+7, N = 1;
    dp[0][0] = 1;
    for(int i = 2; i <= n; i++){
        dp[N][0] = 1;
        for(int j = 1; j <= k; j++){
            dp[N][j] = (dp[N][j-1]+dp[N^1][j])%MOD;
            if(j >= i) dp[N][j] = (dp[N][j]-dp[N^1][j-i]+MOD)%MOD;
        }
        N ^= 1;
    }
    return dp[N^1][k];
}