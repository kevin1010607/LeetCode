#define max(a,b) (((a)>(b))?(a):(b))
int minRefuelStops(int target, int fuel, int** A, int ASz, int* AColSz){
    long long dp[501] = {fuel};
    for(int i = 0; i < ASz; i++)
        for(int j = i; j>=0 && dp[j]>=A[i][0]; j--)
            dp[j+1] = max(dp[j+1], dp[j]+A[i][1]);
    for(int i = 0; i <= ASz; i++)
        if(dp[i] >= target) return i;
    return -1;
}