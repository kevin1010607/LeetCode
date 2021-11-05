class Solution {
public:
    int arrangeCoins(int n) {
        int ret = 0;
        while(n > ret) ret++, n -= ret;
        return ret;
    }
};