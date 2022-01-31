class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int n = colsum.size();
        vector<vector<int>> res(2, vector<int>(n));
        for(int i = 0; i < n; i++){
            switch(colsum[i]){
                case 1:
                    if(upper > lower) res[0][i] = 1, upper--;
                    else res[1][i] = 1, lower--;
                    break;
                case 2:
                    res[0][i] = res[1][i] = 1, upper--, lower--;
                    break;
            }
        }
        if(upper || lower) return {};
        return res;
    }
};