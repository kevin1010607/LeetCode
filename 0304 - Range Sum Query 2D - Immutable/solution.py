class NumMatrix:

    def __init__(self, A: List[List[int]]):
        m, n = len(A), len(A[0])
        self.dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                self.dp[i][j] = self.dp[i-1][j]+self.dp[i][j-1]-self.dp[i-1][j-1]+A[i-1][j-1]

    def sumRegion(self, r1: int, c1: int, r2: int, c2: int) -> int:
        return self.dp[r2+1][c2+1]-self.dp[r2+1][c1]-self.dp[r1][c2+1]+self.dp[r1][c1]


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)