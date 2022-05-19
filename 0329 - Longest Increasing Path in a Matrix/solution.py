from functools import lru_cache
class Solution:
    def longestIncreasingPath(self, A: List[List[int]]) -> int:
        @lru_cache(256)
        def dp(x, y):
            return 1+max([dp(nx, ny) for nx, ny in ((x-1,y),(x,y-1),(x+1,y),(x,y+1))
                        if 0 <= nx < m and 0 <= ny < n and A[nx][ny] > A[x][y]] or [0])
        m, n = len(A), len(A[0])
        return max(dp(i, j) for i in range(m) for j in range(n))