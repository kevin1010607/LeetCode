int change(int amount, int* A, int ASz){
    int dp[5001] = {1};
    for(int i = 0; i < ASz; i++)
        for(int j = A[i]; j <= amount; j++)
            dp[j] += dp[j-A[i]];
    return dp[amount];
}