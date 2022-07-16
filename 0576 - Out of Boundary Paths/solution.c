int findPaths(int m, int n, int maxMove, int startX, int startY){
    int res = 0, MOD = 1e9+7, dir[5] = {1, 0, -1, 0, 1}, dp[2][52][52] = {}, N = 1;
    dp[0][startX+1][startY+1] = 1;
    for(int i = 1; i <= maxMove; i++){
        for(int x = 1; x <= m; x++){
            for(int y = 1; y <= n; y++){
                dp[N][x][y] = 0;
                for(int j = 0; j < 4; j++)
                    dp[N][x][y] = (dp[N][x][y]+dp[N^1][x+dir[j]][y+dir[j+1]])%MOD;
                long long cnt = (x==1)+(x==m)+(y==1)+(y==n);
                res = (res+cnt*dp[N^1][x][y])%MOD;
            }
        }
        N ^= 1;
    }
    return res;
}