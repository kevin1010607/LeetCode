class Solution {
public:
    int countVowelPermutation(int n) {
        const int MOD = 1e9+7;
        vector<long long> dp(5), prev(5, 1);
        for(int i = 2; i <= n; i++){
            dp[0] = (prev[1]+prev[2]+prev[4])%MOD;
            dp[1] = (prev[0]+prev[2])%MOD;
            dp[2] = (prev[1]+prev[3])%MOD;
            dp[3] = prev[2];
            dp[4] = (prev[2]+prev[3])%MOD;
            swap(dp, prev);
        }
        return accumulate(prev.begin(), prev.end(), 0L)%MOD;
    }
};