class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int res = 0, m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n);
        for(int i = 0; i < m; i++){
            stack<int> s;
            for(int j = 0; j <= n; j++){
                int now = (j!=n)?(dp[j]=matrix[i][j]=='1'?dp[j]+1:0):0;
                while(!s.empty() && dp[s.top()]>=now){
                    int top = s.top(); s.pop();
                    int area = dp[top]*(s.empty()?j:j-s.top()-1);
                    res = max(res, area);
                }
                s.push(j);
            }
        }
        return res;
    }
};