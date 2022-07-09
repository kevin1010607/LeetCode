class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        @lru_cache(None)
        def dp(i, j):
            if i == 0 and j == 0:
                return True
            if i == 0:
                return s2[j-1] == s3[j-1] and dp(i, j-1)
            if j == 0:
                return s1[i-1] == s3[i-1] and dp(i-1, j)
            return s2[j-1] == s3[i+j-1] and dp(i, j-1) or s1[i-1] == s3[i+j-1] and dp(i-1, j)
        n1, n2, n3 = len(s1), len(s2), len(s3)
        return n1+n2 == n3 and dp(n1, n2)