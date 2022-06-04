class Solution:
    def totalNQueens(self, n: int) -> int:
        def place(i):
            if i == n:
                return 1
            res = 0
            for j in range(n):
                if not (col[j] or dia1[i+j] or dia2[i-j+n-1]):
                    col[j] = dia1[i+j] = dia2[i-j+n-1] = True
                    res += place(i+1)
                    col[j] = dia1[i+j] = dia2[i-j+n-1] = False
            return res
        col, dia1, dia2 = [False]*n, [False]*(n*2-1), [False]*(n*2-1)
        return place(0)