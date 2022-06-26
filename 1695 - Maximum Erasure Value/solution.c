#define max(a,b) (((a)>(b))?(a):(b))
int maximumUniqueSubarray(int* A, int sz){
    int seen[10001], res = INT_MIN, total = 0, l = 0;
    memset(seen, 0xff, sizeof(seen));
    for(int i = 0; i < sz; i++){
        while(seen[A[i]] >= 0){
            seen[A[l]] = -1;
            total -= A[l++];
        }
        seen[A[i]] = i;
        total += A[i];
        res = max(res, total);
    }
    return res;
}