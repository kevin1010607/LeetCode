/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    for(int i = 0; i < numsSize; i++){
        int idx = abs(nums[i])-1;
        if(nums[idx] > 0) nums[idx] = -nums[idx], (*returnSize)--;
    }
    int *res = (int*)malloc((*returnSize)*sizeof(int));
    for(int i = 0, idx = 0; i < numsSize; i++){
        if(nums[i] > 0) res[idx++] = i+1;
    }
    return res;
}