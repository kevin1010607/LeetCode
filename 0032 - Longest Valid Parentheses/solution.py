class Solution:
    def longestValidParentheses(self, s: str) -> int:
        res, stk = 0, [-1]
        for i in range(len(s)):
            if s[i] == '(':
                stk.append(i)
            else:
                stk.pop()
                if not stk:
                    stk.append(i)
                else:
                    res = max(res, i-stk[-1])
        return res