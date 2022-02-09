class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        from collections import Counter
        return (Counter(t)-Counter(s)).popitem()[0]