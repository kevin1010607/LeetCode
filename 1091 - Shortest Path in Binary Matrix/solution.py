from collections import deque
from itertools import product
class Solution:
    def shortestPathBinaryMatrix(self, A: List[List[int]]) -> int:
        n, q = len(A), deque()
        if A[0][0] or A[-1][-1]:
            return -1
        q.append((0, 0, 1)); A[0][0] = 1
        while q:
            x, y, d = q.popleft()
            if x == n-1 and y == n-1:
                return d
            for i, j in product((-1, 0, 1), repeat=2):
                nx, ny = x+i, y+j
                if 0 <= nx < n and 0 <= ny < n and A[nx][ny] == 0:
                    q.append((nx, ny, d+1)); A[nx][ny] = 1
        return -1