bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity){
    int dp[1005] = {}, cnt = 0;
    for(int i = 0; i < tripsSize; i++){
        dp[trips[i][1]] += trips[i][0];
        dp[trips[i][2]] -= trips[i][0];
    }
    for(int i = 0; i < 1005; i++){
        cnt += dp[i];
        if(cnt > capacity) return false;
    }
    return true;
}