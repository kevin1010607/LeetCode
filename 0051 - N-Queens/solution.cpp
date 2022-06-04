class Solution {
private:
    vector<bool> col, dia1, dia2;
    void place(int i, int n, vector<string>& now, vector<vector<string>>& res){
        if(i == n) {res.push_back(now); return;}
        for(int j = 0; j < n; j++){
            if(col[j] || dia1[i+j] || dia2[i-j+(n-1)]) continue;
            col[j] = dia1[i+j] = dia2[i-j+(n-1)] = true;
            now[i][j] = 'Q';
            place(i+1, n, now, res);
            now[i][j] = '.';
            col[j] = dia1[i+j] = dia2[i-j+(n-1)] = false;
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> now(n, string(n, '.'));
        col.resize(n), dia1.resize(n*2-1), dia2.resize(n*2-1);
        place(0, n, now, res);
        return res;
    }
};