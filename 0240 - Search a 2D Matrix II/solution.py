class Solution:
    def searchMatrix(self, A: List[List[int]], target: int) -> bool:
        m, n, i, j = len(A), len(A[0]), 0, len(A[0])-1
        while i < m and j >= 0:
            if A[i][j] == target:
                return True
            elif A[i][j] < target:
                i += 1
            elif A[i][j] > target:
                j -= 1
        return False