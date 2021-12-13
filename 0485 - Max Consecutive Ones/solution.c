int findMaxConsecutiveOnes(int* nums, int numsSize){
    int res = 0, now = 0;
    for(int i = 0; i < numsSize; i++){
        now = nums[i]?now+1:0;
        res = res>now?res:now;
    }
    return res;
}