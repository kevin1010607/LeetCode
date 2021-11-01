class Solution {
public:
    int m, n;
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O') dfs(i, 0, board);
            if(board[i][n-1] == 'O') dfs(i, n-1, board);
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O') dfs(0, j, board);
            if(board[m-1][j] == 'O') dfs(m-1, j, board);
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void dfs(int x, int y, vector<vector<char>> &board){
        if(x<0||x>=m||y<0||y>=n||board[x][y]!='O') return;
        board[x][y] = '#';
        static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], board);
    }
};