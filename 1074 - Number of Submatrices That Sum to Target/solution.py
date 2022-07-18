from itertools import combinations_with_replacement
class Solution:
    def numSubmatrixSumTarget(self, A: List[List[int]], target: int) -> int:
        res, m, n = 0, len(A), len(A[0])
        for i in range(m):
            for j in range(1, n):
                A[i][j] += A[i][j-1]
        for i, j in combinations_with_replacement(range(n), 2):
            total, mp = 0, {0: 1}
            for k in range(m):
                total += A[k][j]-(A[k][i-1] if i else 0)
                res += mp.get(total-target, 0)
                mp[total] = mp.get(total, 0)+1
        return res