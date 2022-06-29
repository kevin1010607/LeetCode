/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int BIT[20002], sz;
void update(int x, int d){
    for(int i = x+1; i <= sz; i += i&-i)
        BIT[i] += d;
}
int query(int x){
    int res = 0;
    for(int i = x+1; i > 0; i -= i&-i)
        res += BIT[i];
    return res;
}
int* countSmaller(int* A, int n, int* retSz){
    int BASE = 10000;
    *retSz = n, sz = BASE*2+1;
    memset(BIT, 0, sizeof(BIT));
    for(int i = n-1; i >= 0; i--){
        int val = A[i];
        A[i] = query(BASE+(val-1));
        update(BASE+val, 1);
    }
    return A;
}