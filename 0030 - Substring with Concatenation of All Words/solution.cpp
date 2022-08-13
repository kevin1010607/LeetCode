class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& A) {
        int l = s.size(), m = A.size(), n = A[0].size();
        vector<int> res;
        unordered_map<string, int> W;
        for(auto& w : A) W[w]++;
        for(int i = 0; i < n; i++){
            int left = i;
            unordered_map<string, int> t;
            for(int j = i; j <= l-n; j += n){
                string w = s.substr(j, n);
                if(!W.count(w)) {t.clear(); left = j+n; continue;}
                t[w]++;
                while(left<=j && t[w]>W[w]){
                    t[s.substr(left, n)]--;
                    left += n;
                }
                if(j+n-left == m*n) res.push_back(left);
            }
        }
        return res;
    }
};