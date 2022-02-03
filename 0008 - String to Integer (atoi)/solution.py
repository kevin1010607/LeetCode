class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s:
            return 0
        res, MAX, MIN = 0, 2**31-1, -2**31
        sign = -1 if s[0]=='-' else 1
        i = 1 if s[0] in '+-' else 0
        while i<len(s) and s[i].isdigit():
            if res>MAX//10 or (res==MAX//10 and s[i]>'7'):
                return MAX if sign==1 else MIN
            res = 10*res+(ord(s[i])-ord('0')); i += 1
        return sign*res
        