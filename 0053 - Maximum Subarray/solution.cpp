class Solution {
public:
    int maxSubArray(vector<int>& nums, int l, int r){
        if(l > r) return INT_MIN;
        int mid((l+r)/2), tl(0), tr(0);
        int ml = maxSubArray(nums, l, mid-1);
        int mr = maxSubArray(nums, mid+1, r);
        for(int i = mid-1, sum = 0; i >= l; i--) sum += nums[i], tl = max(tl, sum);
        for(int i = mid+1, sum = 0; i <= r; i++) sum += nums[i], tr = max(tr, sum);
        return max(tl+tr+nums[mid], max(ml, mr));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size()-1);
    }
};