class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res, now = 0, 100005
        for i in prices:
            res = max(res, i-now)
            now = min(now, i)
        return res