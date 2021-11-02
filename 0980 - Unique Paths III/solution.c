int uniquePathsIII(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0], cnt = 0, empty = 0, startX, startY;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == 1) startX = i, startY = j;
            if(grid[i][j] == 0) empty++;
        }
    }
    dfs(startX, startY, grid, m, n, empty, 0, &cnt);
    return cnt;
}
void dfs(int x, int y, int **grid, int m, int n, int empty, int step, int *cnt){
    if(x<0||x>=m||y<0||y>=n||grid[x][y]==-1) return;
    if(grid[x][y] == 2){
        if(step == empty+1) (*cnt)++;
        return;
    }
    static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    grid[x][y] = -1;
    for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], grid, m, n, empty, step+1, cnt);
    grid[x][y] = 0;
}