class Solution {
public:
    int poorPigs(int buckets, int die, int test) {
        int n = test/die+1, res = 0;
        while(pow(n, res) < buckets) res++;
        return res;
    }
};