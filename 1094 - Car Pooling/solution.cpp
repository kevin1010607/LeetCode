class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> dp(1005);
        int cnt = 0;
        for(auto& i : trips) dp[i[1]] += i[0], dp[i[2]] -= i[0];
        for(auto i : dp){
            cnt += i;
            if(cnt > capacity) return false;
        }
        return true;
    }
};