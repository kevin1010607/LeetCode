int removeDuplicates(int* nums, int numsSize){
    int idx = 0;
    for(int i = 0; i < numsSize; i++){
        if(idx<1 || nums[i]!=nums[idx-1]) nums[idx++] = nums[i];
    }
    return idx;
}