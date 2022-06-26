class Solution:
    def minDistance(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp = [[0]*(n+1) for _ in range(m+1)]
        for i in range(1, m+1):
            for j in range(1, n+1):
                dp[i][j] = max(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]+(s1[i-1]==s2[j-1]))
        return m+n-2*dp[m][n]