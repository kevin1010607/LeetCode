class Solution {
public:
    int candy(vector<int>& A) {
        int n = A.size();
        vector<int> v(n, 1);
        for(int i = 1; i < n; i++)
            if(A[i] > A[i-1]) v[i] = max(v[i], v[i-1]+1);
        for(int i = n-2; i >= 0; i--)
            if(A[i] > A[i+1]) v[i] = max(v[i], v[i+1]+1);
        return accumulate(v.begin(), v.end(), 0);
    }
};