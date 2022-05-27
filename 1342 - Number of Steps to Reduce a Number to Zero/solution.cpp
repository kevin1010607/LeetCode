class Solution {
public:
    int numberOfSteps(int n) {
        return n?bitset<32>(n).count()+log2(n):0;
    }
};