from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, A: List[int]) -> int:
        dp = []
        for i in A:
            if not dp or dp[-1] < i:
                dp.append(i)
            else:
                dp[bisect_left(dp, i)] = i
        return len(dp)