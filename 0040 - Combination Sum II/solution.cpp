class Solution {
private:
    void solve(int idx, int need, vector<int>& cd , vector<int>& now, vector<vector<int>>& res){
        if(need == 0) {res.push_back(now); return;}
        for(int i = idx; i < cd.size(); i++){
            if(i>idx && cd[i]==cd[i-1]) continue;
            if(cd[i] > need) break;
            now.push_back(cd[i]);
            solve(i+1, need-cd[i], cd, now, res);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> now;
        solve(0, target, candidates, now, res);
        return res;
    }
};