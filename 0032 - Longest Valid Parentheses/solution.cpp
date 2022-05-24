class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size(), open = 0, res = 0;
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(s[i] == '(') open++;
            if(s[i]==')' && open>0){
                dp[i] = 2+dp[i-1];
                if(i-dp[i]>0) dp[i] += dp[i-dp[i]];
                open--;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};