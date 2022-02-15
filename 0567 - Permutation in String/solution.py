class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        t1, t2, n = [0]*26, [0]*26, len(s1)
        for i in s1:
            t1[ord(i)-ord('a')] += 1
        for i in range(len(s2)):
            if i>=n:
                t2[ord(s2[i-n])-ord('a')] -= 1
            t2[ord(s2[i])-ord('a')] += 1
            if t1==t2:
                return True
        return False