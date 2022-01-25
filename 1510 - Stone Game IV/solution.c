bool winnerSquareGame(int n){
    bool dp[100005] = {};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j*j <= i; j++){
            if(!dp[i-j*j]) {dp[i] = true; break;}
        }
    }
    return dp[n];
}