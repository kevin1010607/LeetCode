class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        auto cmp = [](vector<int>& a, vector<int>& b){return a[1]<b[1];};
        sort(points.begin(), points.end(), cmp);
        int res = 0, flag = 0;
        for(auto &v : points){
            if(res==0||flag<v[0]) res++, flag = v[1];
        }
        return res;
    }
};