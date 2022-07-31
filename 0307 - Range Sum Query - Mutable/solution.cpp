class NumArray {
private:
    int sz;
    vector<int> A;
    int query(int idx){
        int res = 0;
        for(int i = idx+1; i > 0; i -= i&-i)
            res += A[i];
        return res;
    }
public:
    NumArray(vector<int>& nums):sz(nums.size()) {
        A.resize(sz+1);
        for(int i = 0; i < sz; i++)
            update(i, nums[i]);
    }
    
    void update(int idx, int val) {
        int dval = val-(query(idx)-query(idx-1));
        for(int i = idx+1; i <= sz; i += i&-i)
            A[i] += dval;
    }
    
    int sumRange(int left, int right) {
        return query(right)-query(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */