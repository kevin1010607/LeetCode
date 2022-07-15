int max(int a, int b){return a>b?a:b;}
int dfs(int x, int y, int **A, int m, int n){
    static int dir[5] = {-1, 0, 1, 0, -1};
    int res = 1;
    A[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x+dir[i], ny = y+dir[i+1];
        if(nx<0||nx>=m||ny<0||ny>=n||!A[nx][ny]) continue;
        res += dfs(nx, ny, A, m, n);
    }
    return res;
}
int maxAreaOfIsland(int** A, int ASz, int* AColSz){
    int res = 0, m = ASz, n = *AColSz;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(A[i][j]) res = max(res, dfs(i, j, A, m, n));
    return res;
}