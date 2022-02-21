class Solution {
private:
    int solve(vector<int>& nums, int l, int r){
        if(l == r) return nums[l];
        int mid = l+(r-l)/2, L = solve(nums, l, mid), R = solve(nums, mid+1, r);
        return count(nums.begin()+l, nums.begin()+r+1, L)>count(nums.begin()+l, nums.begin()+r+1, R)?L:R;
    }
public:
    int majorityElement(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }
};