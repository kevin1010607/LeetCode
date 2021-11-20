class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n), nxt(n);
        int m{}, idx{};
        for(int i = n-1; i >= 0; i--){
            int cnt{}, id{};
            for(int j = i+1; j < n; j++){
                if(nums[j]%nums[i]==0 && dp[j]>cnt){
                    cnt = dp[j], id = j;
                }
            }
            dp[i] = 1+cnt, nxt[i] = id;
            if(dp[i] > m) m = dp[i], idx = i;
        }
        vector<int> res(dp[idx]);
        int k = dp[idx];
        for(int i = 0; i < k; i++){
            res[i] = nums[idx];
            idx = nxt[idx];
        }
        return res;
    }
};