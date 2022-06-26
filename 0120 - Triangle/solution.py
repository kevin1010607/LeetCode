class Solution:
    def minimumTotal(self, A: List[List[int]]) -> int:
        @lru_cache(None)
        def dp(i, j):
            if i == 0:
                return A[0][0]
            if j < 0 or j > i:
                return inf
            return A[i][j]+min(dp(i-1, j-1), dp(i-1, j))
        n = len(A)
        return min(dp(n-1, j) for j in range(n))