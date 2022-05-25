int LB(int *dp, int sz, int val){
    int l = 0, r = sz, mid;
    while(l < r){
        mid = l+(r-l)/2;
        if(dp[mid] >= val) r = mid;
        else l = mid+1;
    }
    return l;
}
int lengthOfLIS(int* A, int sz){
    int dp[2500], len = 0;
    for(int i = 0; i < sz; i++){
        int idx = LB(dp, len, A[i]);
        if(idx == len) dp[len++] = A[i];
        else dp[idx] = A[i];
    }
    return len;
}