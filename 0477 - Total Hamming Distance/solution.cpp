class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        vector<int> v(32, 0);
        for(auto i : nums){
            int idx = 0;
            while(i){
                v[idx++] += i&1;
                i >>= 1;
            }
        }
        for(auto i : v) res += i*(nums.size()-i);
        return res;
    }
};