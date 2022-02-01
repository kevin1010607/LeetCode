class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, now = 10005;
        for(auto i : prices){
            res = max(res, i-now);
            now = min(now, i);
        }
        return res;
    }
};