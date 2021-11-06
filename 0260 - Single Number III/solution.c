/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int *ret = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    int xor1 = 0, xor2 = 0;
    for(int i = 0; i < numsSize; i++) xor1 ^= nums[i];
    int t = xor1&(-(unsigned int)xor1);
    for(int i = 0; i < numsSize; i++) if(t & nums[i]) xor2 ^= nums[i];
    ret[0] = xor2, ret[1] = xor2^xor1;
    return ret;
}