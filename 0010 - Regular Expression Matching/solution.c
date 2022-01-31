bool isMatch(char * s, char * p){
    int i, j;
    bool dp[21][31] = {};
    dp[0][0] = true;
    for(j = 1; p[j-1]; j++) if(p[j-1] == '*') dp[0][j] = dp[0][j-2];
    for(i = 1; s[i-1]; i++){
        for(j = 1; p[j-1]; j++){
            if(p[j-1] == '*'){
                if(p[j-2]=='.' || p[j-2]==s[i-1]) dp[i][j] = dp[i][j-2]||dp[i-1][j];
                else dp[i][j] = dp[i][j-2];
            }
            else if(p[j-1]=='.' || p[j-1]==s[i-1]) dp[i][j] = dp[i-1][j-1];
        }
    }
    return dp[i-1][j-1];
}