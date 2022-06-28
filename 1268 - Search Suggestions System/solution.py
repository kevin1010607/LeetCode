from bisect import bisect_left
class Solution:
    def suggestedProducts(self, A, s):
        A.sort()
        res, prefix, idx = [], '', 0
        for c in s:
            prefix += c
            idx = bisect_left(A, prefix, lo=idx)
            res.append([i for i in A[idx:idx+3] if i.startswith(prefix)])
        return res