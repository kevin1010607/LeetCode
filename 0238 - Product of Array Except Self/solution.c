/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int left = 1, right = 1;
    int *res = (int*)malloc(numsSize*sizeof(int));
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++) res[i] = 1;
    for(int i = 0; i < numsSize; i++){
        res[i] *= left;
        left *= nums[i];
        res[numsSize-1-i] *= right;
        right *= nums[numsSize-1-i];
    }
    return res;
}