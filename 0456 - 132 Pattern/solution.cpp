class Solution {
public:
    bool find132pattern(vector<int>& A) {
        int n = A.size(), s3 = INT_MIN, stk_idx = n;
        for(int i = n-1; i >= 0; i--){
            if(A[i] < s3) return true;
            while(stk_idx<n && A[stk_idx]<A[i]) s3 = A[stk_idx++];
            A[--stk_idx] = A[i];
        }
        return false;
    }
};