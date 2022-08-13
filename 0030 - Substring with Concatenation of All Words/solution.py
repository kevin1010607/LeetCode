from collections import Counter
class Solution:
    def findSubstring(self, s: str, A: List[str]) -> List[int]:
        l, m, n, res, A = len(s), len(A), len(A[0]), [], Counter(A)
        for i in range(n):
            left, t = i, {}
            for j in range(i, l-n+1, n):
                w = s[j:j+n]
                if w not in A:
                    left, t = j+n, {}
                    continue
                t[w] = t.get(w, 0)+1
                while left <= j and t[w] > A[w]:
                    t[s[left:left+n]] -= 1
                    left += n
                if j+n-left == m*n:
                    res.append(left)
        return res