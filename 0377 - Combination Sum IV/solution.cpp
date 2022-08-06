class Solution {
private:
    int solve(int target, vector<int>& A, vector<int>& dp){
        if(target <= 0) return target == 0;
        if(dp[target] != -1) return dp[target];
        int res = 0;
        for(auto i : A)
            res += solve(target-i, A, dp);
        return dp[target] = res;
    }
public:
    int combinationSum4(vector<int>& A, int target) {
        vector<int> dp(target+1, -1);
        return solve(target, A, dp);
    }
};