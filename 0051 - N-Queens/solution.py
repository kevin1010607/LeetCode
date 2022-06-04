class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def place(i):
            if i == n:
                res.append([''.join(s) for s in now])
                return
            for j in range(n):
                if not (col[j] or dia1[i+j] or dia2[i-j+n-1]):
                    col[j] = dia1[i+j] = dia2[i-j+n-1] = True
                    now[i][j] = 'Q'
                    place(i+1)
                    now[i][j] = '.'
                    col[j] = dia1[i+j] = dia2[i-j+n-1] = False
        res, now = [], [['.']*n for _ in range(n)]
        col, dia1, dia2 = [False]*n, [False]*(n*2-1), [False]*(n*2-1)
        place(0)
        return res