class WordFilter:

    def __init__(self, A: List[str]):
        self.m = {}
        for i, s, in enumerate(A):
            n = len(s)
            for j in range(1, n+1):
                p = s[:j]
                for k in range(1, n+1):
                    q = s[-k:]
                    self.m[p+"_"+q] = i

    def f(self, pref: str, suff: str) -> int:
        key = pref+"_"+suff
        return self.m[key] if key in self.m else -1

# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(pref,suff)