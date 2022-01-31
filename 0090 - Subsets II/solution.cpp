class Solution {
private:
    void dfs(bool flag, int idx, vector<int>& now, vector<int>& nums, vector<vector<int>>& res){
        if(idx == nums.size()) {res.push_back(now); return;}
        dfs(false, idx+1, now, nums, res);
        if(idx>0 && nums[idx-1]==nums[idx] && !flag) return;
        now.push_back(nums[idx]);
        dfs(true, idx+1, now, nums, res);
        now.pop_back();
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        sort(nums.begin(), nums.end());
        dfs(false, 0, now, nums, res);
        return res;
    }
};