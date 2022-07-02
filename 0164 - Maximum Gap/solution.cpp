#define F first
#define S second
class Solution {
public:
    int maximumGap(vector<int>& A) {
        auto p = minmax_element(A.begin(), A.end());
        int _min = *p.F, _max = *p.S, bktSz = max(1, (_max-_min)/(int)A.size());
        vector<pair<int, int>> v((_max-_min)/bktSz+1, {INT_MAX, INT_MIN});
        for(auto i : A){
            int idx = (i-_min)/bktSz;
            v[idx].F = min(v[idx].F, i);
            v[idx].S = max(v[idx].S, i);
        }
        int res = 0, prev = _min;
        for(auto& [i, j] : v){
            if(i==INT_MAX && j==INT_MIN) continue;
            res = max(res, i-prev);
            prev = j;
        }
        return res;
    }
};