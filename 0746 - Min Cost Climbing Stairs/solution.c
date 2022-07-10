#define min(a,b) (((a)<(b))?(a):(b))
int minCostClimbingStairs(int* A, int n){
    for(int i = 2; i < n; i++)
        A[i] += min(A[i-1], A[i-2]);
    return min(A[n-1], A[n-2]);
}