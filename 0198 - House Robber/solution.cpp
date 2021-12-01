class Solution {
public:
    int rob(vector<int>& nums) {
        int own = nums[0], none = 0;
        for(int i = 1; i < nums.size(); i++){
            int tmp = none;
            none = max(none, own);
            own = tmp+nums[i];
        }
        return max(own, none);
    }
};