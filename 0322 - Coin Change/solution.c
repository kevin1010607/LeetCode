#define min(a,b) (((a)<(b))?(a):(b))
#define INF 0x3f3f3f3f
int coinChange(int* A, int sz, int n){
    int dp[10001];
    memset(dp, 0x3f, sizeof(dp));
    dp[0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < sz; j++)
            if(i >= A[j]) dp[i] = min(dp[i], 1+dp[i-A[j]]);
    return dp[n]==INF?-1:dp[n];
}