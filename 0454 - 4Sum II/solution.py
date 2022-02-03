class Solution:
    from collections import Counter
    def fourSumCount(self, nums1: List[int], nums2: List[int], nums3: List[int], nums4: List[int]) -> int:
        c = Counter(i+j for i in nums1 for j in nums2)
        return sum(c[-i-j] for i in nums3 for j in nums4)