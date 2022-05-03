class Solution:
    def findUnsortedSubarray(self, A: List[int]) -> int:
        res = [i for i, (a, b) in enumerate(zip(A, sorted(A))) if a != b]
        return res[-1]-res[0]+1 if res else 0