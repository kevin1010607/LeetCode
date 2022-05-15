#define F first
#define S second
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& A) {
        map<int, int> m;
        for(auto& i : A){
            int l = i[0], r = i[1], s = i[0], e = i[1];
            auto it = m.lower_bound(l);
            while(it!=m.end() && it->S<=r){
                s = min(s, it->S);
                e = max(e, it->F);
                it = m.erase(it);
            }
            m[e] = s;
        }
        A.clear();
        for(auto [r, l] : m) A.push_back({l, r});
        return A;
    }
};