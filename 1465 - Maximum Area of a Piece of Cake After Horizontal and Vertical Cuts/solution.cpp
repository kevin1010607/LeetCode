#define F first
#define S second
class Solution {
private:
    int maxGap(vector<int>& A, int sz){
        auto p = minmax_element(A.begin(), A.end());
        int minC = *p.F, maxC = *p.S, bktSz = max(1, (maxC-minC)/(int)A.size());
        vector<pair<int, int>> v((maxC-minC)/bktSz+1, {INT_MAX, INT_MIN});
        for(auto i : A){
            int idx = (i-minC)/bktSz;
            v[idx].F = min(v[idx].F, i);
            v[idx].S = max(v[idx].S, i);
        }
        int res = max(minC, sz-maxC), prev = minC;
        for(auto& [i, j] : v){
            if(i==INT_MAX && j==INT_MIN) continue;
            res = max(res, i-prev);
            prev = j;
        }
        return res;
    }
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        return (long long)maxGap(hc, h)*maxGap(vc, w)%(int)(1e9+7);
    }
};