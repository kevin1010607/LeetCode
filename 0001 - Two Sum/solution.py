class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        table = {}
        for i in range(len(nums)):
            if nums[i] in table: return [i, table[nums[i]]]
            else : table[target-nums[i]] = i
        return []