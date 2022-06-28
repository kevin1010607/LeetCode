class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& A, string s) {
        int n = s.size(), idx = 0;
        string prefix = "";
        vector<vector<string>> res(n);
        sort(A.begin(), A.end());
        for(int i = 0; i < n; i++){
            prefix += s[i];
            idx = lower_bound(A.begin()+idx, A.end(), prefix)-A.begin();
            for(int j = idx; j < min(idx+3, (int)A.size()); j++){
                if(A[j].compare(0, i+1, prefix) == 0)
                    res[i].push_back(A[j]);
            }
        }
        return res;
    }
};