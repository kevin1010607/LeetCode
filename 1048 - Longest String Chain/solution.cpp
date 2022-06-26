class Solution {
public:
    int longestStrChain(vector<string>& A) {
        int res = 0;
        sort(A.begin(), A.end(), [](auto& a, auto& b){return a.size()<b.size();});
        unordered_map<string, int> m;
        for(auto& s : A){
            for(int i = 0; i < s.size(); i++){
                string pre = s.substr(0, i)+s.substr(i+1);
                m[s] = max(m[s], m.count(pre)?m[pre]+1:1);
            }
            res = max(res, m[s]);
        }
        return res;
    }
};