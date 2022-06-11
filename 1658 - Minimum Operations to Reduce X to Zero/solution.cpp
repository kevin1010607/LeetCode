class Solution {
public:
    int minOperations(vector<int>& A, int x) {
        int res = INT_MAX, l = 0, sum = 0, n = A.size();
        int target = accumulate(A.begin(), A.end(), 0)-x;
        if(target == 0) return n;
        for(int i = 0; i < n; i++){
            sum += A[i];
            while(sum>=target && l<=i){
                if(sum == target) res = min(res, n-(i-l+1));
                sum -= A[l++];
            }
        }
        return res==INT_MAX?-1:res;
    }
};