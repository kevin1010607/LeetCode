/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool solve(int x, int y, char *word, int idx, int len, char **board, int m, int n, bool **used){
    if(idx == len) return true;
    if(word[idx] != board[x][y]) return false;
    used[x][y] = true;
    int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
    for(int i = 0; i < 4; i++){
        int nx = x+dx[i], ny = y+dy[i];
        if(nx<0||nx>=m||ny<0||ny>=n||used[nx][ny]) continue;
        if(solve(nx, ny, word, idx+1, len, board, m, n, used)) return true;
    }
    return false;
}
bool search(char *word, int len, char **board, int m, int n){
    bool **used = (bool**)malloc(m*sizeof(bool*)), ret = false;
    for(int i = 0; i < m; i++) used[i] = (bool*)calloc(n, sizeof(bool));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < m; k++) memset(used[i], 0, n*sizeof(bool));
            if(solve(i, j, word, 0, len, board, m, n, used)) {ret = true; break;}
        }
        if(ret) break;
    }
    for(int i = 0; i < m; i++) free(used[i]);
    free(used);
    return ret;
}
char** findWords(char **board, int boardSize, int boardColSize, char **words, int wordsSize, int *returnSize){
    int *record = (int*)malloc(wordsSize*sizeof(int));
    int *wordsLen = (int*)malloc(wordsSize*sizeof(int));
    int idx = 0;
    for(int i = 0; i < wordsSize; i++){
        wordsLen[i] = strlen(words[i]);
        if(search(words[i], wordsLen[i], board, boardSize, boardColsize)) record[idx++] = i;
    }
    char **ret = (char**)malloc(idx*sizeof(char*));
    for(int i = 0; i < idx; i++){
        ret[i] = (char*)malloc((wordsLen[i]+1)*sizeof(char));
        strcpy(ret[i], words[i]);
    }
    *returnSize = idx;
    free(record), free(wordsLen);
    return ret;
}
