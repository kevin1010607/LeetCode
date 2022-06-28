class Solution:
    def minimumLengthEncoding(self, A: List[str]) -> int:
        res, us = 0, set(A)
        for s in A:
            for i in range(1, len(s)):
                us.discard(s[i:])
        return sum(len(s)+1 for s in us)
            