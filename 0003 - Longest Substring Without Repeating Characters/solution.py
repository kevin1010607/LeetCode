class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res, l = 0, ''
        for i in s:
            if i in l: l = l[l.index(i)+1:]
            l += i
            res = max(res, len(l))
        return res