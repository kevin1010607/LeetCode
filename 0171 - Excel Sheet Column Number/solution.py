class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        return reduce(lambda n, c: 26*n+(ord(c)-ord('A')+1), columnTitle, 0)