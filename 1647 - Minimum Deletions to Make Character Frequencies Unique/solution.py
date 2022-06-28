from collections import Counter
class Solution:
    def minDeletions(self, s: str) -> int:
        res, cnt, seen = 0, Counter(s), set()
        for i in cnt.values():
            while i > 0 and i in seen:
                res += 1; i -= 1
            seen.add(i)
        return res