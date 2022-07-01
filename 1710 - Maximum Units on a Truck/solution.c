#define min(a,b) (((a)<(b))?(a):(b))
int maximumUnits(int** A, int n, int* colSz, int sz){
    int bucket[1001] = {}, res = 0;
    for(int i = 0; i < n; i++) bucket[A[i][1]] += A[i][0];
    for(int i = 1000; i > 0; i--){
        if(sz == 0) break;
        res += i*min(sz, bucket[i]);
        sz -= min(sz, bucket[i]);
    }
    return res;
}