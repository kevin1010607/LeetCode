class Solution {
private:
    void solve(int idx, int k, int n, vector<int>& now, vector<vector<int>>& res){
        if(k == 0) {if(n == 0) res.push_back(now);}
        for(int i = idx; i <= 9; i++){
            if(n < i) break;
            now.push_back(i);
            solve(i+1, k-1, n-i, now, res);
            now.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> now;
        solve(1, k, n, now, res);
        return res;
    }
};