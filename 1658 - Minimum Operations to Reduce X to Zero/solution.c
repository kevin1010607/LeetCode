#define min(a,b) (((a)<(b))?(a):(b))
int minOperations(int* A, int n, int x){
    int res = INT_MAX, target = -x, sum = 0, l = 0;
    for(int i = 0; i < n; i++) target += A[i];
    if(target == 0) return n;
    for(int i = 0; i < n; i++){
        sum += A[i];
        while(sum>=target && l<=i) {
            if(sum == target) res = min(res, n-(i-l+1));
            sum -= A[l++];
        }
    }
    return res==INT_MAX?-1:res;
}