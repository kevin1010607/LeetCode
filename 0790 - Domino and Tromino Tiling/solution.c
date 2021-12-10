#define MOD (int)(1e9+7)
int numTilings(int n){
    if(n < 3) return n;
    long long dp3 = 1, dp2 = 1, dp1 = 2, dp;
    for(int i = 3; i <= n; i++){
        dp = (dp3+2*dp1)%MOD; // dp[i] = dp[i-3]+2*dp[i-1]
        dp3 = dp2, dp2 = dp1, dp1 = dp;
    }
    return dp;
}