int totalHammingDistance(int* nums, int numsSize){
    int res = 0, v[32];
    for(int i = 0; i < 32; i++) v[i] = 0;
    for(int i = 0; i < numsSize; i++){
        int idx = 0;
        while(nums[i]){
            v[idx++] += nums[i]&1;
            nums[i] >>= 1;
        }
    }
    for(int i = 0; i < 32; i++) res += v[i]*(numsSize-v[i]);
    return res;
}