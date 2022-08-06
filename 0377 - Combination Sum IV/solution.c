int combinationSum4(int* A, int ASz, int target){
    unsigned dp[1001] = {1};
    for(int i = 1; i <= target; i++)
        for(int j = 0; j < ASz; j++)
            if(i >= A[j]) dp[i] += dp[i-A[j]];
    return dp[target];
}