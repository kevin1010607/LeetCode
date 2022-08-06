class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        while p&1 == 0 and q&1 == 0:
            p >>= 1; q >>= 1;
        return 1-(p&1)+(q&1)