from collections import deque
class Solution:
    def maxResult(self, A: List[int], k: int) -> int:
        q = deque([0])
        for i in range(1, len(A)):
            if q[0] < i-k:
                q.popleft()
            A[i] += A[q[0]]
            while q and A[i] > A[q[-1]]:
                q.pop()
            q.append(i)
        return A[-1]