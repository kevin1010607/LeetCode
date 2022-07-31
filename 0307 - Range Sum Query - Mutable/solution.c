typedef struct {
    int sz, *A;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSz) {
    NumArray *res = (NumArray*)malloc(sizeof(NumArray));
    res->sz = numsSz;
    res->A = (int*)calloc(res->sz+1, sizeof(int));
    for(int i = 0; i < res->sz; i++)
        numArrayUpdate(res, i, nums[i]);
    return res;
}

int numArrayQuery(NumArray* obj, int idx){
    int res = 0;
    for(int i = idx+1; i > 0; i -= i&-i)
        res += obj->A[i];
    return res;
}

void numArrayUpdate(NumArray* obj, int idx, int val) {
    int dval = val-(numArrayQuery(obj, idx)-numArrayQuery(obj, idx-1));
    for(int i = idx+1; i <= obj->sz; i += i&-i)
        obj->A[i] += dval;
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return numArrayQuery(obj, right)-numArrayQuery(obj, left-1);
}

void numArrayFree(NumArray* obj) {
    free(obj->A);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/