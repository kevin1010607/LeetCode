class Solution:
    def permuteUnique(self, A: List[int]) -> List[List[int]]:
        res, n = [], len(A)
        def solve(idx):
            if idx == n:
                res.append(A.copy()); return
            s = set()
            for i in range(idx, n):
                if A[i] not in s:
                    s.add(A[i])
                    A[idx], A[i] = A[i], A[idx]
                    solve(idx+1)
                    A[idx], A[i] = A[i], A[idx]
        solve(0)
        return res