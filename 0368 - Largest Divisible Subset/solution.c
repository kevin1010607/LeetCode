/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b){
    return *(const int*)a > *(const int*)b;
}
int* largestDivisibleSubset(int* nums, int numsSize, int* returnSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    int dp[1005], nxt[1005], m = 0, idx;
    for(int i = numsSize-1; i >= 0; i--){
        int cnt = 0, id;
        for(int j = i+1; j < numsSize; j++){
            if(nums[j]%nums[i]==0 && dp[j]>cnt){
                cnt = dp[j], id = j;
            }
        }
        dp[i] = 1+cnt, nxt[i] = id;
        if(dp[i] > m) m = dp[i], idx = i;
    }
    int *res = (int*)malloc(dp[idx]*sizeof(int));
    *returnSize = dp[idx];
    int k = dp[idx];
    for(int i = 0; i < k; i++){
        res[i] = nums[idx];
        idx = nxt[idx];
    }
    return res;
}