class Solution {
public:
    int MOD = 1e9+7;
    int numTilings(int n) {
        if(n < 3) return n;
        long long d2 = 1, d1 = 2, t2 = 1, t1 = 2, d, t;
        for(int i = 3; i <= n; i++){
            d = (d1+d2+2*t2)%MOD; // d[i] = d[i-1]+d[i-2]+2*t[i-2]
            t = (d1+t1)%MOD; // t[i] = d[i-1]+t[i-1]
            d2 = d1, d1 = d, t2 = t1, t1 = t;
        }
        return d;
    }
};