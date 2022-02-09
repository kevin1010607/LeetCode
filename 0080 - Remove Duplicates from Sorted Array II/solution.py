class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        idx = 0
        for i in nums:
            if idx<2 or i!=nums[idx-2]:
                nums[idx] = i; idx += 1
        return idx