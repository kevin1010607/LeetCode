class Solution {
public:
    int m, n, cnt, empty;
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size(), cnt = empty = 0;
        int startX, startY;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) startX = i, startY = j;
                if(grid[i][j] == 0) empty++;
            }
        }
        dfs(startX, startY, grid, 0);
        return cnt;
    }
    void dfs(int x, int y, vector<vector<int>> &grid, int step){
        if(grid[x][y] == 2){
            if(step == empty+1) cnt++;
            return;
        }
        static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++){
            int nx = x+dx[i], ny = y+dy[i];
            if(nx<0||nx>=m||ny<0||ny>=n||grid[nx][ny]==-1) continue;
            grid[x][y] = -1;
            dfs(nx, ny, grid, step+1);
            grid[x][y] = 0;
        }
    }
};