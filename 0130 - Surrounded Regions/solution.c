void solve(char** board, int boardSize, int* boardColSize){
    int m = boardSize, n = boardColSize[0];
    for(int i = 0; i < m; i++){
        if(board[i][0] == 'O') dfs(i, 0, board, m, n);
        if(board[i][n-1] == 'O') dfs(i, n-1, board, m, n);
    }
    for(int j = 0; j < n; j++){
        if(board[0][j] == 'O') dfs(0, j, board, m, n);
        if(board[m-1][j] == 'O') dfs(m-1, j, board, m, n);
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '#') board[i][j] = 'O';
        }
    }
}
void dfs(int x, int y, char **board, int m, int n){
    if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') return;
    board[x][y] = '#';
    static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], board, m, n);
}