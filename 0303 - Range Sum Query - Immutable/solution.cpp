class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int>& A) {
        int n = A.size();
        dp.resize(n+1);
        for(int i = 1; i <= n; i++) dp[i] = dp[i-1]+A[i-1];
    }
    
    int sumRange(int l, int r) {
        return dp[r+1]-dp[l];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */