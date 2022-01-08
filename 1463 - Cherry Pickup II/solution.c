int max(int a, int b) {return a>b?a:b;}
int cherryPickup(int** grid, int gridSize, int* gridColSize){
    int dp[75][75][75] = {}, m = gridSize, n = *gridColSize, d[] = {-1, 0, 1};
    for(int r = m-1; r >= 0; r--){
        for(int c1 = 0; c1 < n; c1++){
            for(int c2 = 0; c2 < n; c2++){
                for(int d1 = 0; d1 < 3; d1++){
                    for(int d2 = 0; d2 < 3; d2++){
                        int t1 = c1+d[d1], t2 = c2+d[d2];
                        if(t1<0||t1>=n||t2<0||t2>=n) continue;
                        dp[r][c1][c2] = max(dp[r][c1][c2], dp[r+1][t1][t2]);
                    }
                }
                dp[r][c1][c2] += grid[r][c1]+grid[r][c2]*(c1==c2?0:1);
            }
        }
    }
    return dp[0][0][n-1];
}