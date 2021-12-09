int max(int a, int b) {return a>b?a:b;}
bool canJump(int* nums, int numsSize){
    int range = 0;
    for(int i = 0; i <= range; i++){
        range = max(range, i+nums[i]);
        if(range >= numsSize-1) return true;
    }
    return false;
}