class Solution:
    from collections import deque
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        res, dq = [], deque()
        for i, n in enumerate(nums):
            if dq and dq[0]==i-k:
                dq.popleft()
            while dq and nums[dq[-1]]<n:
                dq.pop()
            dq.append(i)
            if i>=k-1:
                res.append(nums[dq[0]])
        return res