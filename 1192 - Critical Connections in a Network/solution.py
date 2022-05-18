class Solution:
    def criticalConnections(self, n: int, A: List[List[int]]) -> List[List[int]]:
        def dfs(idx, p, d):
            low[idx] = d
            for i in graph[idx]:
                if i == p:
                    continue
                if low[i] == -1:
                    dfs(i, idx, d+1)
                low[idx] = min(low[idx], low[i])
                if low[i] >= d+1:
                    res.append([idx, i])
        graph, low, res = [[] for _ in range(n)], [-1]*n, []
        for i, j in A:
            graph[i].append(j)
            graph[j].append(i)
        dfs(0, -1, 0)
        return res