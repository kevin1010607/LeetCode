class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int res = 0, now = 0;
        for(int i : nums){
            now = i?now+1:0;
            res = max(res, now);
        }
        return res;
    }
};