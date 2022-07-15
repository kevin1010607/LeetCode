class Solution {
private:
    int m, n, dir[5] = {-1, 0, 1, 0, -1};
    int dfs(int x, int y, vector<vector<int>>& A){
        int res = 1;
        A[x][y] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x+dir[i], ny = y+dir[i+1];
            if(nx<0||nx>=m||ny<0||ny>=n||!A[nx][ny]) continue;
            res += dfs(nx, ny, A);
        }
        return res;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& A) {
        m = A.size(), n = A[0].size();
        int res = 0;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(A[i][j]) res = max(res, dfs(i, j, A));
        return res;
    }
};