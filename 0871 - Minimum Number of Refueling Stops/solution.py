import heapq
class Solution:
    def minRefuelStops(self, target: int, fuel: int, A: List[List[int]]) -> int:
        q = []
        A.append([target, 0])
        for p, f in A:
            while q and fuel < p:
                fuel += -heapq.heappop(q)
            if fuel < p:
                return -1
            heapq.heappush(q, -f)
        return len(A)-len(q)