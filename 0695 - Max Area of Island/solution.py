class Solution:
    def maxAreaOfIsland(self, A: List[List[int]]) -> int:
        A = {(i, j): v for i, r in enumerate(A) for j, v in enumerate(r)}
        def solve(i, j):
            return A.pop((i, j), 0) and 1+sum(solve(*k) for k in ((i+1, j), (i-1, j), (i, j+1), (i, j-1)))
        return max(solve(*k) for k in set(A))