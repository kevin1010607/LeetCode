class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int d = INT_MAX;
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        for(int i = 1; i < arr.size(); i++){
            int now = arr[i]-arr[i-1];
            if(now <= d){
                if(now < d) d = now, res.clear();
                res.push_back({arr[i-1], arr[i]});
            }
        }
        return res;
    }
};