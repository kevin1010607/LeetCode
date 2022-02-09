class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        idx = 0
        for i in nums:
            if idx<1 or i!=nums[idx-1]:
                nums[idx] = i; idx += 1
        return idx