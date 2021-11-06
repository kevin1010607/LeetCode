int singleNumber(int* nums, int numsSize){
    int ret = 0;
    for(int i = 0; i < 32; i++){
        int c = 0;
        for(int j = 0; j < numsSize; j++) if(nums[j]&((unsigned int)1<<i)) c++;
        ret |= (unsigned int)(c%3)<<i;
    }
    return ret;
}