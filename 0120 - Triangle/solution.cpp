class Solution {
public:
    int minimumTotal(vector<vector<int>>& A) {
        int n = A.size(), INF = 0x3f3f3f3f;
        for(int i = 1; i < n; i++)
            for(int j = 0; j <= i; j++)
                A[i][j] += min(j!=0?A[i-1][j-1]:INF, j!=i?A[i-1][j]:INF);
        return *min_element(A.back().begin(), A.back().end());
    }
};