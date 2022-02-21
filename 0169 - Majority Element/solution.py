class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        res, cnt = 0, 0
        for i in nums:
            if cnt == 0:
                res = i
            cnt += (1 if i == res else -1)
        return res