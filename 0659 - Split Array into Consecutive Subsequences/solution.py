from collections import defaultdict, Counter
class Solution:
    def isPossible(self, A: List[int]) -> bool:
        l, r = Counter(A), defaultdict(int)
        for i in A:
            if l[i] == 0:
                continue
            l[i] -= 1
            if r[i-1] != 0:
                r[i-1] -= 1; r[i] += 1
            elif l[i+1] != 0 and l[i+2] != 0:
                l[i+1] -= 1; l[i+2] -= 1; r[i+2] += 1
            else:
                return False
        return True