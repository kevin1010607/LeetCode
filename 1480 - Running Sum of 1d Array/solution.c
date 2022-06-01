/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* A, int n, int* sz){
    int *res = (int*)malloc(n*sizeof(int));
    *sz = n, res[0] = A[0];
    for(int i = 1; i < n; i++) res[i] = res[i-1]+A[i];
    return res;
}