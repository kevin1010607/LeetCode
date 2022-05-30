class Solution:
    def divide(self, A: int, B: int) -> int:
        INT_MAX, INT_MIN = 2147483647, -2147483648
        if A == INT_MIN:
            if B == -1:
                return INT_MAX
            if B == 1:
                return INT_MIN
            return self.divide(A+1, B) if B&1 else self.divide(A>>1, B>>1)
        if B == INT_MIN:
            return 0
        a, b, res = abs(A), abs(B), 0
        for i in range(31, -1, -1):
            if a>>i >= b:
                res |= 1<<i; a -= b<<i
        return -res if (A<0)^(B<0) else res
        