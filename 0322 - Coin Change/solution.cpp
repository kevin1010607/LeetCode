class Solution {
public:
    int coinChange(vector<int>& A, int n) {
        vector<int> dp(n+1, n+1); dp[0] = 0;
        for(int i = 1; i <= n; i++)
            for(auto j : A)
                if(i >= j) dp[i] = min(dp[i], 1+dp[i-j]);
        return dp[n]==n+1?-1:dp[n];
    }
};