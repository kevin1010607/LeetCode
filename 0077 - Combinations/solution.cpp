class Solution {
private:
    void solve(int idx, int n, int k, vector<int>& now, vector<vector<int>>& res){
        if(now.size() == k) {res.push_back(now); return;}
        for(int i = idx; i <= n; i++){
            now.push_back(i);
            solve(i+1, n, k, now, res);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> now;
        solve(1, n, k, now, res);
        return res;
    }
};