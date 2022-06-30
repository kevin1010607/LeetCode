int cmp(const void *a, const void *b){
    return *(const int*)a-*(const int*)b;
}
int minMoves2(int* A, int n){
    int res = 0;
    qsort(A, n, sizeof(int), cmp);
    for(int i = 0; i < n/2; i++)
        res += A[n-1-i]-A[i];
    return res;
}