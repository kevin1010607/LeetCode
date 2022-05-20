class Solution:
    def uniquePathsWithObstacles(self, A: List[List[int]]) -> int:
        m, n = len(A), len(A[0])
        dp = [0, 1]+[0]*(n-1);
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[j] = 0 if A[i-1][j-1] else dp[j]+dp[j-1]
        return dp[-1]