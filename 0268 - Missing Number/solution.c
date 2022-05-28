int missingNumber(int* A, int n){
    int res = n*(n+1)/2;
    for(int i = 0; i < n; i++) res -= A[i];
    return res;
}