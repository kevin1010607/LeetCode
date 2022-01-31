class Solution {
private:
    void dfs(int idx, vector<int>& now, vector<int>& nums, vector<vector<int>>& res){
        if(idx == nums.size()) {res.push_back(now); return;}
        dfs(idx+1, now, nums, res);
        now.push_back(nums[idx]);
        dfs(idx+1, now, nums, res);
        now.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> now;
        dfs(0, now, nums, res);
        return res;
    }
};