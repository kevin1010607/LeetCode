class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        res, c = 0, Counter(nums)
        for i in c:
            if i-k in c:
                res += (k!=0 or c[i]>1)
        return res