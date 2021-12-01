#define max(a,b) a>b?a:b
int rob(int* nums, int numsSize){
    int own = nums[0], none = 0;
    for(int i = 1; i < numsSize; i++){
        int tmp = none;
        none = max(own, none);
        own = tmp+nums[i];
    }
    return max(own, none);
}