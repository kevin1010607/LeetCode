class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, s = 0;
        unordered_map<int, int> um{{0, 1}};
        for(auto i : nums){
            s += i;
            if(um.count(s-k)) res += um[s-k];
            um[s]++;
        }
        return res;
    }
};