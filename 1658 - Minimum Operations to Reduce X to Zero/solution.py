class Solution:
    def minOperations(self, A: List[int], x: int) -> int:
        res, s, l, n, target = float('inf'), 0, 0, len(A), sum(A)-x
        if target == 0:
            return n
        for i, v in enumerate(A):
            s += v
            while s >= target and l <= i:
                if s == target:
                    res = min(res, n-(i-l+1))
                s -= A[l]; l += 1
        return -1 if res == float('inf') else res
        