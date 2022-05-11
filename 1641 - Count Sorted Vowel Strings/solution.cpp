class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp{0, 1, 0, 0, 0, 0};
        for(int i = 0; i < n; i++)
            for(int j = 1; j <= 5; j++)
                dp[j] += dp[j-1];
        return dp[1]+dp[2]+dp[3]+dp[4]+dp[5];
    }
};