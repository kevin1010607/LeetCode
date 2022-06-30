from statistics import median_low
class Solution:
    def minMoves2(self, A: List[int]) -> int:
        mid = median_low(A)
        return sum(abs(i-mid) for i in A)