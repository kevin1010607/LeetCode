class Solution:
    def findMaxForm(self, A: List[str], m: int, n: int) -> int:
        dp = [[0]*(n+1) for _ in range(m+1)]
        for s in A:
            cnt0 = s.count('0'); cnt1 = len(s)-cnt0
            for i in range(m, cnt0-1, -1):
                for j in range(n, cnt1-1, -1):
                    dp[i][j] = max(dp[i][j], 1+dp[i-cnt0][j-cnt1])
        return dp[m][n]