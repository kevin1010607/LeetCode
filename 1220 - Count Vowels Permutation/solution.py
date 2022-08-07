class Solution:
    def countVowelPermutation(self, n: int) -> int:
        a = e = i = o = u = 1
        for _ in range(n-1):
            a, e, i, o, u = e+i+u, a+i, e+o, i, i+o
        return (a+e+i+o+u)%int(1e9+7)