#define max(a,b) (((a)>(b))?(a):(b))
int minDistance(char *s1, char *s2){
    int dp[501][501] = {}, i, j;
    for(i = 1; s1[i-1]; i++)
        for(j = 1; s2[j-1]; j++)
            dp[i][j] = s1[i-1]==s2[j-1]?dp[i-1][j-1]+1:max(dp[i-1][j], dp[i][j-1]);
    return (i-1)+(j-1)-2*dp[i-1][j-1];
}