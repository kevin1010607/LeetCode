class Solution {
public:
    int change(int amount, vector<int>& A) {
        vector<int> dp(amount+1);
        dp[0] = 1;
        for(auto i : A)
            for(int j = i; j <= amount; j++)
                dp[j] += dp[j-i];
        return dp[amount];
    }
};