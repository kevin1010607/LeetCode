#define ll long long
#define MOD (int)(1e9+7)
class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        ll l = min(a, b), r = (ll)(1e18), c = lcm(a, b);
        while(l <= r){
            ll mid = l+(r-l)/2;
            ll cnt = mid/a+mid/b-mid/c;
            if(cnt >= n) r = mid-1;
            else l = mid+1;
        }
        return l%MOD;
    }
};