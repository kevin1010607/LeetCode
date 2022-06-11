class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res, start, d = 0, 0, {}
        for i, c in enumerate(s):
            if c in d:
                start = max(start, d[c]+1)
            res, d[c] = max(res, i-start+1), i
        return res