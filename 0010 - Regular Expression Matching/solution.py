class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        id, dp = 0, [[False for _ in range(len(p)+1)] for _ in range(2)]
        for i in range(len(s)+1):
            dp[id][0] = not i
            for j in range(1, len(p)+1):
                if p[j-1]=='*':
                    dp[id][j] = dp[id][j-2] or (i and dp[id^1][j] and p[j-2] in ('.', s[i-1]))
                else:
                    dp[id][j] = i and dp[id^1][j-1] and p[j-1] in ('.', s[i-1])
            id ^= 1
        return dp[id^1][len(p)]