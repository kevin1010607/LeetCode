class Solution:
    def longestStrChain(self, A: List[str]) -> int:
        res, m = 0, {}
        A.sort(key=len)
        for s in A:
            m[s] = 1
            for i in range(len(s)):
                pre = s[:i]+s[i+1:]
                if pre in m:
                    m[s] = max(m[s], m[pre]+1)
            res = max(res, m[s])
        return res