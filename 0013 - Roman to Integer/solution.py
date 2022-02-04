class Solution:
    def romanToInt(self, s: str) -> int:
        t = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        res = t[s[0]]
        for i in range(1, len(s)):
            res += t[s[i]]
            if t[s[i]] > t[s[i-1]]:
                res -= 2*t[s[i-1]]
        return res