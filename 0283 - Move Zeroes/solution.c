void moveZeroes(int* nums, int numsSize){
    int idx = 0, t;
    for(int i = 0; i < numsSize; i++){
        if(nums[i]) t = nums[i], nums[i] = nums[idx], nums[idx] = t, idx++;
    }
}