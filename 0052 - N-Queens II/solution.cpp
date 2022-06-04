class Solution {
private:
    vector<bool> col, dia1, dia2;
    int place(int i, int n){
        if(i == n) return 1;
        int res = 0;
        for(int j = 0; j < n; j++){
            if(col[j] || dia1[i+j] || dia2[i-j+n-1]) continue;
            col[j] = dia1[i+j] = dia2[i-j+n-1] = true;
            res += place(i+1, n);
            col[j] = dia1[i+j] = dia2[i-j+n-1] = false;
        }
        return res;
    }
public:
    int totalNQueens(int n) {
        col.resize(n), dia1.resize(n*2-1), dia2.resize(n*2-1);
        return place(0, n);
    }
};