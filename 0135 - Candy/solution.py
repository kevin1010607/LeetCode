class Solution:
    def candy(self, A: List[int]) -> int:
        n, v = len(A), [1]*len(A)
        for i in range(n-1):
            if A[i] < A[i+1]:
                v[i+1] = max(v[i+1], v[i]+1)
        for i in range(n-1)[::-1]:
            if A[i] > A[i+1]:
                v[i] = max(v[i], v[i+1]+1)
        return sum(v)