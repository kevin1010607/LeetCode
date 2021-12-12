bool canPartition(int* nums, int numsSize){
    int sum = 0;
    for(int i = 0; i < numsSize; i++) sum += nums[i];
    if(sum%2) return false;
    bool dp[10001];
    memset(dp, 0, sizeof(dp));
    dp[0] = true;
    for(int i = 0; i < numsSize; i++){
        for(int j = sum/2; j >= nums[i]; j--){
            dp[j] = dp[j]||dp[j-nums[i]];
        }
    }
    return dp[sum/2];
}