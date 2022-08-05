int count(int x, int **A, int n){
    int res = 0, j = n-1;
    for(int i = 0; i < n; i++){
        while(j>=0 && A[i][j]>x) j--;
        res += (j+1);
    }
    return res;
}
int kthSmallest(int** A, int ASz, int* AColSz, int k){
    int n = ASz, l = A[0][0], r = A[n-1][n-1], mid;
    while(l <= r){
        mid = l+(r-l)/2;
        if(count(mid, A, n) >= k) r = mid-1;
        else l = mid+1;
    }
    return l;
}