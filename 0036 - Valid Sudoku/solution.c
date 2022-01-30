bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    bool h[9][9] = {}, v[9][9] = {}, b[9][9] = {};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.') continue;
            int id = board[i][j]-1-'0';
            if(h[i][id] || v[j][id] || b[i/3*3+j/3][id]) return false;
            h[i][id] = v[j][id] = b[i/3*3+j/3][id] = true;
        }
    }
    return true;
}