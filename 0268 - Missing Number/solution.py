class Solution:
    def missingNumber(self, A: List[int]) -> int:
        return len(A)*(len(A)+1)//2-sum(A)