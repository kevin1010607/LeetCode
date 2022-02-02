class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        res, hs, hp, n = [], [0]*26, [0]*26, len(p)
        for i in range(n):
            hp[ord(p[i])-ord('a')] += 1
        for i in range(len(s)):
            if i>=n: hs[ord(s[i-n])-ord('a')] -= 1
            hs[ord(s[i])-ord('a')] += 1
            if hs==hp: res.append(i-n+1)
        return res