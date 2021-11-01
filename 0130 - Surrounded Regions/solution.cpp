class Solution {
public:
    int m, n;
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        for(int i = 1; i < m-1; i++){
            if(board[i][0] == 'O') dfs(i, 1, board);
            if(board[i][n-1] == 'O') dfs(i, n-2, board);
        }
        for(int j = 1; j < n-1; j++){
            if(board[0][j] == 'O') dfs(1, j, board);
            if(board[m-1][j] == 'O') dfs(m-2, j, board);
        }
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
    void dfs(int x, int y, vector<vector<char>> &board){
        if(x<1||x>=m-1||y<1||y>=n-1||board[x][y]!='O') return;
        board[x][y] = '#';
        static int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
        for(int i = 0; i < 4; i++) dfs(x+dx[i], y+dy[i], board);
    }
};