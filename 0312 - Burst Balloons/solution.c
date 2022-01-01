int max(int a, int b) {return a>b?a:b;}
int maxCoins(int* nums, int numsSize){
    int dp[505][505], n = numsSize;
    memset(dp, 0, sizeof(dp));
    for(int len = 1; len <= n; len++){
        for(int i = 0; i+len <= n; i++){
            int j = i+len-1;
            int left = i==0?1:nums[i-1];
            int right = j==n-1?1:nums[j+1];
            for(int k = i; k <= j; k++){
                int L = k==i?0:dp[i][k-1];
                int R = k==j?0:dp[k+1][j];
                dp[i][j] = max(dp[i][j], L+left*nums[k]*right+R);
            }
        }
    }
    return dp[0][n-1];
}