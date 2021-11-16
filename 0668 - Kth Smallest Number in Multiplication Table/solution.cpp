class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 0, r = m*n, mid;
        while(l < r){
            mid = l+(r-l)/2;
            if(check(mid, m, n, k)) r = mid;
            else l = mid+1;
        }
        return l;
    }
    int check(int t, int m, int n, int k){
        int s = 0;
        for(int i = 1; i <= m; i++) s += min(n, t/i);
        return s >= k;
    }
};