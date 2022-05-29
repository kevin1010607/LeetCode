class Solution:
    def maxProduct(self, A: List[str]) -> int:
        d = {}
        for s in A:
            key = reduce(lambda res, c: res|(1<<ord(c)-ord('a')), s, 0)
            d[key] = max(d.get(key, 0), len(s))
        return max([d[v1]*d[v2] for v1 in d for v2 in d if not v1 & v2] or [0])