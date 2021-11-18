class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++){
            int idx = abs(nums[i])-1;
            if(nums[idx] > 0) nums[idx] = -nums[idx], n--;
        }
        vector<int> res(n);
        for(int i = 0, idx = 0; i < nums.size(); i++){
            if(nums[i] > 0) res[idx++] = i+1;
        }
        return res;
    }
};