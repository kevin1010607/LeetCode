class Solution:
    def findPaths(self, m: int, n: int, maxMove: int, startX: int, startY: int) -> int:
        @lru_cache(None)
        def dp(step, x, y):
            if not (0 <= x < m and 0 <= y < n):
                return 1
            return sum(dp(step-1, *p) for p in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)))%MOD if step else 0
        MOD = int(1e9+7)
        return dp(maxMove, startX, startY)