from collections import Counter
class Solution:
    def minSetSize(self, A: List[int]) -> int:
        res, n, A = 0, len(A)//2, sorted(Counter(A).values(), reverse=True)
        while n > 0:
            n -= A[res]
            res += 1
        return res