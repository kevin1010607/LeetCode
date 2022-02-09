class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int res = 0;
        unordered_map<int, int> m;
        for(auto i : nums) m[i]++;
        for(auto& [i, v] : m){
            if(m.count(i-k)) res += (k||v>1);
        }
        return res;
    }
};