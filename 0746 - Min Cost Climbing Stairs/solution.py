class Solution:
    def minCostClimbingStairs(self, A: List[int]) -> int:
        @lru_cache(None)
        def dp(n):
            if n < 0:
                return 0
            return A[n]+min(dp(n-1), dp(n-2))
        return min(dp(len(A)-1), dp(len(A)-2))