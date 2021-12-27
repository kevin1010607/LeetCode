class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int res = 0;
        for(int i = 0; n; i++){
            res |= (n&1^1)<<i;
            n >>= 1;
        }
        return res;
    }
};