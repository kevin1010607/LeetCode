class Solution:
    def isValid(self, s: str) -> bool:
        stack, d = [], {'(':')', '{':'}', '[':']'}
        for i in s:
            if i in d:
                stack.append(d[i])
            elif not stack or i!=stack.pop():
                return False
        return not stack