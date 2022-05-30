#define abs(a) (((a)>0)?(a):(-a))
int divide(int A, int B){
    if(A == INT_MIN){
        if(B == -1) return INT_MAX;
        if(B == 1) return INT_MIN;
        return B&1?divide(A+1, B):divide(A>>1, B>>1);
    }
    if(B == INT_MIN) return 0;
    int a = abs(A), b = abs(B), res = 0;
    for(int i = 31; i >= 0; i--)
        if(a>>i >= b) res |= 1<<i, a -= b<<i;
    return (A<0)^(B<0)?-res:res;
}