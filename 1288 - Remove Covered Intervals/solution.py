class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        res, r = 0, -1
        intervals.sort(key=lambda x:(x[0],-x[1]))
        for i, j in intervals:
            if j > r:
                res += 1; r = j;
        return res