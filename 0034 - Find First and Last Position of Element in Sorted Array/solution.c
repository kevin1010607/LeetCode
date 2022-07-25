/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int lower(int *A, int n, int target){
    int l = 0, r = n-1, mid;
    while(l <= r){
        mid = l+(r-l)/2;
        if(A[mid] >= target) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int upper(int *A, int n, int target){
    int l = 0, r = n-1, mid;
    while(l <= r){
        mid = l+(r-l)/2;
        if(A[mid] > target) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int* searchRange(int* A, int n, int target, int* returnSz){
    int *res = (int*)malloc(2*sizeof(int));
    *returnSz = 2;
    int l = lower(A, n, target), r = upper(A, n, target);
    if(l==n || A[l]!=target) res[0] = res[1] = -1;
    else res[0] = l, res[1] = r-1;
    return res;
}