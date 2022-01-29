bool putNext(int idx, char **board, bool h[9][9], bool v[9][9], bool b[9][9]){
    for(int p = idx; p < 81; p++){
        int i = p/9, j = p%9;
        if(board[i][j] != '.') continue;
        for(int id = 0; id < 9; id++){
            if(h[i][id] || v[j][id] || b[i/3*3+j/3][id]) continue;
            board[i][j] = '0'+id+1;
            h[i][id] = v[j][id] = b[i/3*3+j/3][id] = true;
            if(putNext(p+1, board, h, v, b)) return true;
            h[i][id] = v[j][id] = b[i/3*3+j/3][id] = false;
            board[i][j] = '.';
        }
        return false;
    }
    return true;
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    bool h[9][9] = {}, v[9][9] = {}, b[9][9] = {};
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.') continue;
            int id = board[i][j]-1-'0';
            h[i][id] = v[j][id] = b[i/3*3+j/3][id] = true;
        }
    }
    putNext(0, board, h, v, b);
}