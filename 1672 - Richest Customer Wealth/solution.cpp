class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int res = 0;
        for(auto& i : accounts){
            int now = 0;
            for(auto j : i) now += j;
            res = max(res, now);
        }
        return res;
    }
};