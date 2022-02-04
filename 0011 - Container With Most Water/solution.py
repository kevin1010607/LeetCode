class Solution:
    def maxArea(self, height: List[int]) -> int:
        l, r, res = 0, len(height)-1, 0
        while l < r:
            if height[l] < height[r]:
                res = max(res, (r-l)*height[l]); l += 1
            else:
                res = max(res, (r-l)*height[r]); r -= 1
        return res;