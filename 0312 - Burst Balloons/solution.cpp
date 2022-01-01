class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for(int len = 3; len <= n; l++){
            for(int i = 0; i+len <= n; i++){
                int j = i+len-1;
                for(int k = i+1; k < j; k++)
                    dp[i][j] = max(dp[i][j], dp[i][k]+dp[k][j]+nums[i]*nums[k]*nums[j]);
            }   
        }
        return dp[0][n-1];
    }
};