int place(int i, int n, bool *col, bool *dia1, bool *dia2){
    if(i == n) return 1;
    int res = 0;
    for(int j = 0; j < n; j++){
        if(col[j] || dia1[i+j] || dia2[i-j+n-1]) continue;
        col[j] = dia1[i+j] = dia2[i-j+n-1] = true;
        res += place(i+1, n, col, dia1, dia2);
        col[j] = dia1[i+j] = dia2[i-j+n-1] = false;
    }
    return res;
}
int totalNQueens(int n){
    bool col[9] = {}, dia1[17] = {}, dia2[17] = {};
    return place(0, n, col, dia1, dia2);
}