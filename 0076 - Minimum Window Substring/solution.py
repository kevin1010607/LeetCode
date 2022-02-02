class Solution:
    from collections import Counter
    def minWindow(self, s: str, t: str) -> str:
        m, l, start, L, cnt = Counter(t), 0, -1, float('inf'), len(t)
        for r, c in enumerate(s):
            if m[c]>0:
                cnt -= 1
            m[c] -= 1
            while cnt==0:
                if r-l+1<L:
                    start, L = l, r-l+1
                if m[s[l]] == 0:
                    cnt += 1
                m[s[l]], l = m[s[l]]+1, l+1
        return '' if start==-1 else s[start:start+L]