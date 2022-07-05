class Solution:
    def longestConsecutive(self, A: List[int]) -> int:
        res, A = 0, set(A)
        for i in A:
            if i-1 not in A:
                r = i+1
                while r in A:
                    r += 1
                res = max(res, r-i)
        return res