class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        def Nsum(nums, l, r, target, N, now, res):
            if N == 2:
                while l < r:
                    s = nums[l]+nums[r]
                    if s == target:
                        res.append(now+[nums[l], nums[r]])
                        l += 1; r -= 1
                        while l<r and nums[l]==nums[l-1]:
                            l += 1
                        while l<r and nums[r]==nums[r+1]:
                            r -= 1
                    elif s < target:
                        l += 1
                    else:
                        r -= 1
            else:
                for i in range(l, r+1):
                    if i==l or (i>l and nums[i]!=nums[i-1]):
                        Nsum(nums, i+1, r, target-nums[i], N-1, now+[nums[i]], res)
        res = []
        nums.sort()
        Nsum(nums, 0, len(nums)-1, target, 4, [], res)
        return res