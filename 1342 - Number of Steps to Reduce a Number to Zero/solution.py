class Solution:
    def numberOfSteps(self, n: int) -> int:
        s = bin(n)[2:]
        return s.count('1')+len(s)-1