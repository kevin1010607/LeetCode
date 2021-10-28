class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for(int i = 0; i < nums.size(); i++){
            int l = i+1, r = nums.size()-1;
            while(l < r){
                int L = nums[l], R = nums[r], sum = nums[i]+L+R;
                if(sum == 0){
                    v.push_back({nums[i], L, R});
                    while(l<r && nums[l]==L) l++;
                    while(l<r && nums[r]==R) r--;
                }
                else if(sum < 0) l++;
                else if(sum > 0) r--;
            }
            while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        }
        return v;
    }
};