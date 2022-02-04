class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n, res = len(nums), sum(nums[:3])
        nums.sort()
        for i, v in enumerate(nums):
            l, r = i+1, n-1
            while l < r:
                s = nums[i]+nums[l]+nums[r]
                if s == target:
                    return s
                if abs(s-target) < abs(res-target):
                    res = s
                if s < target:
                    l += 1
                else:
                    r -= 1
        return res