class Solution:
    def wiggleMaxLength(self, A: List[int]) -> int:
        up = down = 1
        for i in range(len(A)-1):
            if A[i+1] > A[i]:
                up = down+1
            elif A[i+1] < A[i]:
                down = up+1
        return max(up, down)