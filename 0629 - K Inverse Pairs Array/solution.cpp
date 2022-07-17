class Solution {
public:
    int kInversePairs(int n, int k) {
        const int MOD = 1e9+7;
        vector<vector<int>> dp(2, vector<int>(k+1));
        dp[0][0] = 1;
        for(int i = 2; i <= n; i++){
            dp[1][0] = 1;
            for(int j = 1; j <= k; j++){
                dp[1][j] = (dp[1][j-1]+dp[0][j])%MOD;
                if(j >= i) dp[1][j] = (dp[1][j]-dp[0][j-i]+MOD)%MOD;
            }
            swap(dp[0], dp[1]);
        }
        return dp[0][k];
    }
};