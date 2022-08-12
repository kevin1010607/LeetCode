class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        int res = 0, MOD = 1e9+7, n = A.size();
        unordered_map<int, int> m;
        sort(A.begin(), A.end());
        for(int i = 0; i < n; i++){
            m[A[i]] = 1;
            for(int j = 0; j < i; j++){
                if(A[i]%A[j] || !m.count(A[i]/A[j])) continue;
                m[A[i]] = (m[A[i]]+(long long)m[A[j]]*m[A[i]/A[j]])%MOD;
            }
            res = (res+m[A[i]])%MOD;
        }
        return res;
    }
};