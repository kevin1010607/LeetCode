from collections import Counter
class Solution:
    def firstUniqChar(self, s: str) -> int:
        m = [s.index(i) for i, v in Counter(s).items() if v == 1]
        return min(m) if m else -1