class Solution:
    def find132pattern(self, A: List[int]) -> bool:
        s3, stk = -inf, []
        for i in A[-1::-1]:
            if i < s3:
                return True
            while stk and stk[-1] < i:
                s3 = stk.pop()
            stk.append(i)
        return False