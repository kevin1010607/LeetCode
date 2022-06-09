/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* A, int sz, int target, int* returnSz){
    int *res = (int*)malloc(2*sizeof(int));
    *returnSz = 2;
    int l = 0, r = sz-1;
    while(l < r){
        if(A[l]+A[r] == target){
            res[0] = l+1, res[1] = r+1;
            return res;
        }
        else if(A[l]+A[r] > target) r--;
        else l++;
    }
    return res;
}