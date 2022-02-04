class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        res, s, m = 0, 0, {0:-1}
        for i, v in enumerate(nums):
            s += 1 if v else -1
            res = max(res, i-m.setdefault(s, i))
        return res