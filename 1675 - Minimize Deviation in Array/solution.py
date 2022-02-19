class Solution:
    def minimumDeviation(self, nums: List[int]) -> int:
        import heapq
        h = [-(i*2 if i&1 else i) for i in nums]
        res, mi = float('inf'), -max(h)
        heapq.heapify(h)
        while len(h) == len(nums):
            ma = -heapq.heappop(h)
            res = min(res, ma-mi)
            if ma%2 == 0:
                heapq.heappush(h, -ma//2)
                mi = min(mi, ma//2)
        return res