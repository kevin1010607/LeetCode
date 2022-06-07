class Solution:
    def merge(self, A: List[int], m: int, B: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        idx1, idx2, idx = m-1, n-1, m+n-1
        while idx2 >= 0:
            if idx1 >= 0 and A[idx1] > B[idx2]:
                A[idx] = A[idx1]; idx1 -= 1
            else:
                A[idx] = B[idx2]; idx2 -= 1
            idx -= 1
        