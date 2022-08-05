import heapq
class Solution:
    def kthSmallest(self, A: List[List[int]], k: int) -> int:
        q = [(v, 0, i) for i, v in enumerate(A[0])]
        heapq.heapify(q)
        for _ in range(k-1):
            v, i, j = heapq.heappop(q)
            if i != len(A)-1:
                heapq.heappush(q, (A[i+1][j], i+1, j))
        return q[0][0]