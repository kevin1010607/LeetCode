int cmp(const void *a, const void *b){
    int *ia = *(int**)a, *ib = *(int**)b;
    return !(ia[0]<ib[0] || (ia[0]==ib[0]&&ia[1]>ib[1]));
}
int LB(int *dp, int sz, int val){
    int l = 0, r = sz, mid;
    while(l < r){
        mid = l+(r-l)/2;
        if(dp[mid] >= val) r = mid;
        else l = mid+1;
    }
    return l;
}
int maxEnvelopes(int** A, int sz, int* p){
    qsort(A, sz, sizeof(int*), cmp);
    int dp[100001], len = 0;
    for(int i = 0; i < sz; i++){
        int idx = LB(dp, len, A[i][1]);
        if(idx == len) dp[len++] = A[i][1];
        else dp[idx] = A[i][1];
    }
    return len;
}