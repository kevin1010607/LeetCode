class Solution {
private:
    vector<vector<int>> mul(vector<vector<int>>& A, vector<vector<int>>& B){
        vector<vector<int>> res(A.size(), vector<int>(B[0].size()));
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < B[0].size(); j++)
                for(int k = 0; k < A[0].size(); k++)
                    res[i][j] += A[i][k]*B[k][j];
        return res;
    }
public:
    int fib(int n) {
        if(n < 2) return n;
        vector<vector<int>> E{{1, 1}, {1, 0}}, M{{1, 0}, {0, 1}};
        for(int i = n-1; i > 0; i >>= 1){
            if(i & 1) M = mul(M, E);
            E = mul(E, E);
        }
        return M[0][0];
    }
};