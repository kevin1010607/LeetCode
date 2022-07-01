from operator import itemgetter
class Solution:
    def maximumUnits(self, A: List[List[int]], sz: int) -> int:
        A.sort(key=itemgetter(1), reverse=True)
        res = 0
        for i, j in A:
            if sz == 0:
                break
            res += j*min(sz, i)
            sz -= min(sz, i)
        return res