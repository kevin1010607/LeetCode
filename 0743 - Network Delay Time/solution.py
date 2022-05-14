import heapq
from collections import defaultdict
class Solution:
    def networkDelayTime(self, A: List[List[int]], n: int, k: int) -> int:
        q, dist, graph = [(0, k)], {}, defaultdict(list)
        for u, v, w in A:
            graph[u].append((v, w))
        while q:
            d, idx = heapq.heappop(q)
            if idx not in dist:
                dist[idx] = d
                for i, v in graph[idx]:
                    heapq.heappush(q, (dist[idx]+v, i))
        return max(dist.values()) if len(dist) == n else -1