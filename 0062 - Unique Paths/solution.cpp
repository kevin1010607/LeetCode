class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> b(n, 1);
        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                b[j] += b[j-1];
            }
        }
        return b[n-1];
    }
};