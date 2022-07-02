#define max(a,b) (((a)>(b))?(a):(b))
int cmp(const void *a, const void *b){
    return *(const int*)a>*(const int*)b;
}
int maxGap(int *A, int ASz, int sz){
    qsort(A, ASz, sizeof(int), cmp);
    int res = max(A[0], sz-A[ASz-1]);
    for(int i = 1; i < ASz; i++) res = max(res, A[i]-A[i-1]);
    return res;
}
int maxArea(int h, int w, int* hc, int hcSz, int* vc, int vcSz){
    return (long long)maxGap(hc, hcSz, h)*maxGap(vc, vcSz, w)%(int)(1e9+7);
}