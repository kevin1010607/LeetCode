class Solution {
public:
    int findUnsortedSubarray(vector<int>& A) {
        int n = A.size(), l = -1, r = -2, ma = INT_MIN, mi = INT_MAX;
        for(int i = 0; i < n; i++){
            ma = max(ma, A[i]);
            if(A[i] < ma) r = i;
            mi = min(mi, A[n-1-i]);
            if(A[n-1-i] > mi) l = n-1-i;
        }
        return r-l+1;
    }
};