class Solution {
public:
    bool canJump(vector<int>& nums) {
        int range = 0;
        for(int i = 0; i <= range; i++){
            range = max(range, i+nums[i]);
            if(range >= nums.size()-1) return true;
        }
        return false;
    }
};