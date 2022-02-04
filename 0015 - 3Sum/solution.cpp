class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int l = i+1, r = n-1;
            while(l < r){
                int L = nums[l], R = nums[r], s = nums[i]+L+R;
                if(s == 0){
                    res.push_back({nums[i], L, R});
                    while(l<r && nums[l]==L) l++;
                    while(l<r && nums[r]==R) r--;
                }
                else s<0?(l++):(r--);
            }
        }
        return res;
    }
};