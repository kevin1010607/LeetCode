class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        st = min(strs, key=len)
        for i, c in enumerate(st):
            for s in strs:
                if s[i] != c:
                    return st[:i]
        return st