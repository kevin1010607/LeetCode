class Solution:
    def numFactoredBinaryTrees(self, A: List[int]) -> int:
        @lru_cache(None)
        def dp(n):
            return 1+sum(dp(i)*dp(n//i) for i in A if n%i == 0 and n//i in A)
        A = set(A)
        return sum(dp(i) for i in A)%int(1e9+7)