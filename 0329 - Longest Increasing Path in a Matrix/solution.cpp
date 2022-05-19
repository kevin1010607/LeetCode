class Solution {
private:
    int m, n, d[5] = {-1, 0, 1, 0, -1};
    int dfs(int x, int y, vector<vector<int>>& dp, vector<vector<int>>& A){
        int res = 1;
        for(int i = 0; i < 4; i++){
            int nx = x+d[i], ny = y+d[i+1];
            if(nx<0||nx>=m||ny<0||ny>=n||A[nx][ny]<=A[x][y]) continue;
            res = max(res, 1+(dp[nx][ny]?:dfs(nx, ny, dp, A)));
        }
        return dp[x][y] = res;
    }
public:
    int longestIncreasingPath(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                res = max(res, dfs(i, j, dp, A));
        return res;
    }
};