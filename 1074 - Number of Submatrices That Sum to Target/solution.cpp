class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& A, int target) {
        int res = 0, m = A.size(), n = A[0].size();
        for(int i = 0; i < m; i++)
            for(int j = 1; j < n; j++)
                A[i][j] += A[i][j-1];
        unordered_map<int, int> um;
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                um = {{0, 1}};
                int total = 0;
                for(int k = 0; k < m; k++){
                    total += A[k][j]-(i?A[k][i-1]:0);
                    if(um.count(total-target))
                        res += um[total-target];
                    um[total]++;
                }
            }
        }
        return res;
    }
};