int hammingDistance(int x, int y){
    int bit = x^y, res = 0;
    while(bit){
        res += bit&1;
        bit >>= 1;
    }
    return res;
}