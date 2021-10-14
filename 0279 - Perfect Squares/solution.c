#define INF 0x3f3f3f3f
#define min(a,b) a<b?a:b
int numSquares(int n){
    int *dp = (int*)malloc((n+1)*sizeof(int));
    for(int i = 0; i <= n; i++) dp[i] = i?INF:0;
    for(int i = 1; i*i <= n; i++) for(int j = i*i; j <= n; j++) dp[j] = min(dp[j], dp[j-i*i]+1);
    int ret = dp[n];
    free(dp);
    return ret;
}