class Solution:
    def combinationSum4(self, A: List[int], target: int) -> int:
        @lru_cache(None)
        def dp(n):
            if n <= 0:
                return int(n == 0)
            return sum(dp(n-i) for i in A)
        return dp(target)