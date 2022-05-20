class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& A) {
        int m = A.size(), n = A[0].size();
        vector<int> dp(n+1);
        dp[1] = 1;
        for(int i = 1; i <= m; i++)
            for(int j = 1; j <= n; j++)
                dp[j] = A[i-1][j-1]?0:dp[j]+dp[j-1];
        return dp[n];
    }
};