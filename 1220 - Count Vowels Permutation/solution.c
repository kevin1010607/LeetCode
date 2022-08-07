int countVowelPermutation(int n){
    long long dp[2][5] = {1, 1, 1, 1, 1}, MOD = 1e9+7, N = 1;
    for(int i = 2; i <= n; i++){
        dp[N][0] = (dp[N^1][1]+dp[N^1][2]+dp[N^1][4])%MOD;
        dp[N][1] = (dp[N^1][0]+dp[N^1][2])%MOD;
        dp[N][2] = (dp[N^1][1]+dp[N^1][3])%MOD;
        dp[N][3] = dp[N^1][2];
        dp[N][4] = (dp[N^1][2]+dp[N^1][3])%MOD;
        N ^= 1;
    }
    return (dp[N^1][0]+dp[N^1][1]+dp[N^1][2]+dp[N^1][3]+dp[N^1][4])%MOD;
}