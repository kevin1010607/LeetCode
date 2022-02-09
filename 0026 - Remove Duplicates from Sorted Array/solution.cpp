class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0;
        for(auto i : nums) if(idx<1 || i!=nums[idx-1]) nums[idx++] = i;
        return idx;
    }
};