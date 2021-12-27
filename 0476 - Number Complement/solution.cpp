class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        for(int i = 0; num; i++){
            res |= (((num&1)^1)<<i);
            num >>= 1;
        }
        return res;
    }
};