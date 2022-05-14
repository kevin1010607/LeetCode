from collections import defaultdict
class Solution:
    def subdomainVisits(self, A: List[str]) -> List[str]:
        d = defaultdict(int)
        for s in A:
            t, dom = s.split()
            d[dom] += int(t)
            for i in range(len(dom)):
                if dom[i] == '.':
                    d[dom[i+1:]] += int(t)
        return [str(v)+" "+s for s, v in d.items()]