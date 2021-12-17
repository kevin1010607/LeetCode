class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = m>0?matrix[0].size():0;
        vector<int> dp(n+1, 0);
        int res = 0, prev = 0;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                int tmp = dp[j];
                dp[j] = matrix[i-1][j-1]=='1'?min({prev, dp[j], dp[j-1]})+1:0;
                res = max(res, dp[j]);
                prev = tmp;
            }
        }
        return res*res;
    }
};