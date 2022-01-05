class Solution {
public:
    void dfs(int idx, string &s, vector<vector<bool>>& dp, vector<vector<string>>& res, vector<string>& path){
        if(idx == s.size()){
            res.push_back(path);
            return;
        }
        for(int i = idx; i < s.size(); i++){
            if(!dp[idx][i]) continue;
            path.push_back(s.substr(idx, i-idx+1));
            dfs(i+1, s, dp, res, path);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
            if(i!=n-1 && s[i]==s[i+1]) dp[i][i+1] = true;
        }
        for(int len = 3; len <= n; len++){
            for(int i = 0; i <= n-len; i++){
                int j = i+len-1;
                if(dp[i+1][j-1] && s[i]==s[j]) dp[i][j] = true;
            }
        }
        vector<vector<string>> res;
        vector<string> path;
        dfs(0, s, dp, res, path);
        return res;
    }
};