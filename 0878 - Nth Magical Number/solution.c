#define ll long long
#define MOD (int)(1e9+7)
int gcd(int a, int b) {return b?gcd(b, a%b):a;}
int nthMagicalNumber(int n, int a, int b){
    ll lcm = a*b/gcd(a, b), u = lcm/a+lcm/b-1, pos = lcm*(n/u), r = n%u, i = a, j = b, idx = 0;
    while(r--){
        if(i < j) idx = i, i += a;
        else if(i > j) idx = j, j += b;
    }
    return (pos+idx)%MOD;
}