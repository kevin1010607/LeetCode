#define max(a,b) (((a)>(b))?(a):(b))
int findMaxForm(char **A, int l, int m, int n){
    int dp[101][101] = {};
    for(int i = 0; i < l; i++){
        int cnt0 = 0, cnt1 = 0;
        for(int j = 0; A[i][j]; j++) A[i][j]=='0'?cnt0++:cnt1++;
        for(int j = m; j >= cnt0; j--)
            for(int k = n; k >= cnt1; k--)
                dp[j][k] = max(dp[j][k], 1+dp[j-cnt0][k-cnt1]);
    }
    return dp[m][n];
}