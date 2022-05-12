class Solution {
private:
    void solve(int idx, vector<int> A, vector<vector<int>>& res){
        if(idx == A.size()) {res.emplace_back(A); return;}
        for(int i = idx; i < A.size(); i++){
            if(i!=idx && A[i]==A[idx]) continue;
            swap(A[i], A[idx]);
            solve(idx+1, A, res);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& A) {
        vector<vector<int>> res;
        sort(A.begin(), A.end());
        solve(0, A, res);
        return res;
    }
};