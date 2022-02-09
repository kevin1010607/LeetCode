class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(auto& i : nums) if(i) swap(i, nums[idx]), idx++;
    }
};