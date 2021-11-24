class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& list1, vector<vector<int>>& list2) {
        int n1 = list1.size(), n2 = list2.size(), idx1 = 0, idx2 = 0;
        vector<vector<int>> res;
        while(idx1<n1 && idx2<n2){
            int s = max(list1[idx1][0], list2[idx2][0]), e = min(list1[idx1][1], list2[idx2][1]);
            if(s <= e) res.push_back({s,e});
            (list1[idx1][1]<list2[idx2][1])?(idx1++):(idx2++);
        }
        return res;
    }
};