class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        import operator
        return reduce(operator.xor, nums)