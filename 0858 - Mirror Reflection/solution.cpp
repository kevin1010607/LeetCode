class Solution {
public:
    int mirrorReflection(int p, int q) {
        int lcm = p*q/gcd(p, q);
        p = lcm/p, q = lcm/q;
        return q&1?p&1:2;
    }
};