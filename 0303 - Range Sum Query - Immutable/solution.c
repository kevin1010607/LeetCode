typedef struct {
    int *dp, n;
} NumArray;

NumArray* numArrayCreate(int* A, int n) {
    NumArray *res = (NumArray*)malloc(sizeof(NumArray));
    res->n = n;
    res->dp = (int*)calloc(n+1, sizeof(int));
    for(int i = 1; i <= n; i++) res->dp[i] = res->dp[i-1]+A[i-1];
    return res;
}

int numArraySumRange(NumArray* obj, int l, int r) {
    return obj->dp[r+1]-obj->dp[l];
}

void numArrayFree(NumArray* obj) {
    free(obj->dp);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/