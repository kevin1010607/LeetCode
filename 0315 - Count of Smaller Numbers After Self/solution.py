class BIT:
    def __init__(self, sz):
        self.sz = sz
        self.v = [0]*(sz+1)
    
    def update(self, x, d):
        x += 1
        while x <= self.sz:
            self.v[x] += d
            x += x&-x
            
    def query(self, x):
        x += 1; res = 0
        while x > 0:
            res += self.v[x]
            x -= x&-x
        return res
    
class Solution:
    def countSmaller(self, A: List[int]) -> List[int]:
        n, BASE, b = len(A), 10000, BIT(20001)
        for i in range(n-1, -1, -1):
            val = A[i]
            A[i] = b.query(BASE+(val-1))
            b.update(BASE+val, 1)
        return A