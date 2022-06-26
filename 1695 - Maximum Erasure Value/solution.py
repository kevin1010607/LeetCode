class Solution:
    def maximumUniqueSubarray(self, A: List[int]) -> int:
        res, total, l, seen = -inf, 0, 0, set()
        for i, v in enumerate(A):
            while v in seen:
                seen.remove(A[l])
                total -= A[l]; l += 1
            seen.add(v)
            total += v
            res = max(res, total)
        return res