class Solution {
private:
    int dp[75][75][75];
    int dfs(int r, int c1, int c2, vector<vector<int>>& grid){
        int m = grid.size(), n = grid[0].size();
        if(r>=m||c1<0||c1>=n||c2<0||c2>=n) return 0;
        if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
        for(int d1 : {-1, 0, 1}){
            for(int d2 : {-1, 0, 1}){
                dp[r][c1][c2] = max(dp[r][c1][c2], dfs(r+1, c1+d1, c2+d2, grid));
            }
        }
        dp[r][c1][c2] += grid[r][c1]+grid[r][c2]*(c1==c2?0:1);
        return dp[r][c1][c2];
    }
public:
    int cherryPickup(vector<vector<int>>& grid) {
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, grid[0].size()-1, grid);
    }
};