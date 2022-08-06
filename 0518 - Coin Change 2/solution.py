class Solution:
    def change(self, amount: int, A: List[int]) -> int:
        @lru_cache(None)
        def dp(i, amt):
            if amt <= 0 or i == len(A):
                return int(amt == 0)
            return dp(i, amt-A[i])+dp(i+1, amt)
        A.sort(reverse=True)
        return dp(0, amount)