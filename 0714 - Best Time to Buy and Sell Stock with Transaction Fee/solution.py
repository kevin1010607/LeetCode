class Solution:
    def maxProfit(self, prices: List[int], fee: int) -> int:
        s1, s2 = 0, -prices[0]
        for i in prices:
            s1, s2 = max(s1, s2+i-fee), max(s2, s1-i)
        return s1
        