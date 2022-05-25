from bisect import bisect_left
class Solution:
    def maxEnvelopes(self, A: List[List[int]]) -> int:
        dp = []
        A.sort(key=lambda x: (x[0], -x[1]))
        for w, h in A:
            if not dp or dp[-1] < h:
                dp.append(h)
            else:
                dp[bisect_left(dp, h)] = h
        return len(dp)