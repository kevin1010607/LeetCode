class Solution:
    def backspaceCompare(self, s1: str, s2: str) -> bool:
        i1, i2, n1, n2 = len(s1)-1, len(s2)-1, 0, 0
        while True:
            while i1>=0 and (n1 or s1[i1]=='#'):
                n1 += 1 if s1[i1] == '#' else -1
                i1 -= 1
            while i2>=0 and (n2 or s2[i2]=='#'):
                n2 += 1 if s2[i2] == '#' else -1
                i2 -= 1
            if i1<0 or i2<0 or s1[i1]!=s2[i2]:
                return i1 == i2 == -1
            i1, i2 = i1-1, i2-1
        return true