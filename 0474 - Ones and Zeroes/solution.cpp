class Solution {
public:
    int findMaxForm(vector<string>& A, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1));
        for(auto& s : A){
            int cnt0 = 0, cnt1 = 0;
            for(auto c : s) c=='0'?cnt0++:cnt1++;
            for(int i = m; i >= cnt0; i--)
                for(int j = n; j >= cnt1; j--)
                    dp[i][j] = max(dp[i][j], 1+dp[i-cnt0][j-cnt1]);
        }
        return dp[m][n];
    }
};