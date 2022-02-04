class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size(), id = 0;
        vector<vector<bool>> dp(2, vector<bool>(n+1));
        for(int i = 0; i <= m; i++){
            dp[id][0] = !i;
            for(int j = 1; j <= n; j++){
                if(p[j-1] == '*') dp[id][j] = dp[id][j-2]||(i&&dp[id^1][j]&&(p[j-2]=='.'||p[j-2]==s[i-1]));
                else dp[id][j] = i&&dp[id^1][j-1]&&(p[j-1]=='.'||p[j-1]==s[i-1]);
            }
            id ^= 1;
        }
        return dp[id^1][n];
    }
};