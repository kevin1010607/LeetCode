int uniquePathsWithObstacles(int** grid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize, n = *obstacleGridColSize;
    int b[105];
    b[0] = grid[0][0]?0:1;
    for(int j = 1; j < n; j++) b[j] = grid[0][j]?0:b[j-1];
    for(int i = 1; i < m; i++){
        b[0] = grid[i][0]?0:b[0];
        for(int j = 1; j < n; j++){
            b[j] = grid[i][j]?0:b[j]+b[j-1];
        }
    }
    return b[n-1];
}