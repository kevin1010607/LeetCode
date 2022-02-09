class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int id = 0;
        for(auto i : nums) if(id<2 || i!=nums[id-2]) nums[id++] = i;
        return id;
    }
};