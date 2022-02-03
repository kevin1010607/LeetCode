class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows==1:
            return s
        L, row, dir = ['']*numRows, 0, -1
        for c in s:
            L[row] += c
            if row in {0, numRows-1}:
                dir = -dir
            row += dir
        return ''.join(L)
        