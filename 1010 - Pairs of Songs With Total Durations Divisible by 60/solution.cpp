class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int res = 0;
        vector<int> v(60);
        for(auto i : time){
            res += v[(60-i%60)%60];
            v[i%60]++;
        }
        return res;
    }
};