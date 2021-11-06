class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor1 = 0, xor2 = 0;
        for(int i : nums) xor1 ^= i;
        int t = xor1&(-(unsigned int)xor1);
        for(int i : nums) if(t & i) xor2 ^= i;
        return {xor2, xor2^xor1};
    }
};