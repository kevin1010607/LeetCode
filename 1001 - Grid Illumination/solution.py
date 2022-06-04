from collections import defaultdict
from itertools import product
class Solution:
    def gridIllumination(self, n: int, L: List[List[int]], Q: List[List[int]]) -> List[int]:
        res, s = [], {(i, j) for i, j in L}
        row, col, dia1, dia2 = defaultdict(int), defaultdict(int), defaultdict(int), defaultdict(int)
        for i, j in s:
            row[i] += 1; col[j] += 1; dia1[i+j] += 1; dia2[i-j] += 1
        for i, j in Q:
            res.append(int(row[i]+col[j]+dia1[i+j]+dia2[i-j] > 0))
            for x, y in product((i-1, i, i+1), (j-1, j, j+1)):
                if (x, y) in s:
                    row[x] -= 1; col[y] -= 1; dia1[x+y] -= 1; dia2[x-y] -= 1
                    s.remove((x, y))
        return res