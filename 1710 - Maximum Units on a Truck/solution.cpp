class Solution {
public:
    int maximumUnits(vector<vector<int>>& A, int sz) {
        int res = 0;
        sort(A.begin(), A.end(), [](auto& a, auto& b){return a[1]>b[1];});
        for(auto& i : A){
            if(sz == 0) break;
            res += i[1]*min(sz, i[0]);
            sz -= min(sz, i[0]);
        }
        return res;
    }
};