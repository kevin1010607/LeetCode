from functools import lru_cache
class Solution:
    def coinChange(self, A: List[int], n: int) -> int:
        @lru_cache(None)
        def dp(k):
            if k == 0:
                return 0
            if all(k < i for i in A):
                return n+1
            return 1+min(dp(k-i) for i in A if k >= i)
        return -1 if dp(n) >= n+1 else dp(n)