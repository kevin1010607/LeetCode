bool isInterleave(char * s1, char * s2, char * s3){
    int i, j, dp[101] = {};
    for(i = 0; !i || s1[i-1]; i++){
        for(j = 0; !j || s2[j-1]; j++){
            if(i+j && !s3[i+j-1]) return false;
            if(i==0 && j==0) dp[j] = 1;
            else if(i == 0) dp[j] = dp[j-1]&&s2[j-1]==s3[j-1];
            else if(j == 0) dp[j] = dp[j]&&s1[i-1]==s3[i-1];
            else dp[j] = (dp[j-1]&&s2[j-1]==s3[i+j-1])||(dp[j]&&s1[i-1]==s3[i+j-1]);
        }
    }
    return !s3[i+j-2] && dp[j-1];
}