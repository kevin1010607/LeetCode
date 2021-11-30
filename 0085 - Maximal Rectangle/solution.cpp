class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0) return 0;
        int m = matrix.size(), n = matrix[0].size(), res = 0;
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++){
            stack<int> s; s.push(-1);
            for(int j = 0; j <= n; j++){
                int val = (j!=n)?(dp[j]=matrix[i][j]=='1'?dp[j]+1:0):0;
                while(s.top()!=-1 && dp[s.top()]>=val){
                    int l, r = j-1, h = dp[s.top()];
                    s.pop();
                    l = s.top();
                    res = max(res, h*(r-l));
                }
                s.push(j);
            }
        }
        return res;
    }
};