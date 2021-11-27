class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res(nums[0]), ma(nums[0]), mi(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int tmp = ma;
            ma = max({tmp*nums[i], mi*nums[i], nums[i]});
            mi = min({tmp*nums[i], mi*nums[i], nums[i]});
            res = max(res, ma);
        }
        return res;
    }
};