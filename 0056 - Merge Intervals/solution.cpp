class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int idx = 0;
        for(auto& i : intervals){
            if(i[0] <= intervals[idx][1]) intervals[idx][1] = max(intervals[idx][1], i[1]);
            else intervals[++idx] = i;
        }
        intervals.resize(idx+1);
        return intervals;
    }
};