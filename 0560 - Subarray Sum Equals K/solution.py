class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        res, s, d = 0, 0, {0:1}
        for i in nums:
            s += i
            res += d.get(s-k, 0)
            d[s] = d.get(s, 0)+1
        return res