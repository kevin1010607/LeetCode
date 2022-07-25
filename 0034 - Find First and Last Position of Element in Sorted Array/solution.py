from bisect import bisect_left, bisect_right
class Solution:
    def searchRange(self, A: List[int], target: int) -> List[int]:
        l, r = bisect_left(A, target), bisect_right(A, target)
        return [-1, -1] if l == len(A) or A[l] != target else [l, r-1]