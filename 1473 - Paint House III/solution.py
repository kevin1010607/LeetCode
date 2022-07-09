class Solution:
    def minCost(self, A: List[int], cost: List[List[int]], m: int, n: int, target: int) -> int:
        @lru_cache(None)
        def dp(i, j, k):
            if not (1 <= j <= i+1) or (A[i] and A[i] != k):
                return inf
            if i == 0:
                return 0 if A[i] else cost[i][k-1]
            res = min(dp(i-1, j-(p!=k), p) for p in range(1, n+1))
            return res+(0 if A[i] else cost[i][k-1])
        res = min(dp(m-1, target, p) for p in range(1, n+1))
        return res if res < inf else -1