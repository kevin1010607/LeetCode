#define max(a,b) (((a)>(b))?(a):(b))
int maximumGap(int* A, int n){
    int res = 0, e = 1, base = 0xf, bkt[100005];
    for(int i = 0; i < 8; i++){
        int cnt[16] = {};
        for(int j = 0; j < n; j++)
            cnt[(A[j]/e)&base]++;
        for(int j = 1; j < 16; j++)
            cnt[j] += cnt[j-1];
        for(int j = n-1; j >= 0; j--)
            bkt[--cnt[(A[j]/e)&base]] = A[j];
        for(int j = 0; j < n; j++)
            A[j] = bkt[j];
        e = (unsigned int)e<<4;
    }
    for(int i = 1; i < n; i++)
        res = max(res, A[i]-A[i-1]);
    return res;
}