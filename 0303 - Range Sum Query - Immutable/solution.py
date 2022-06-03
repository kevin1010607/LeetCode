from itertools import accumulate
class NumArray:

    def __init__(self, A: List[int]):
        self.dp = list(accumulate(A))

    def sumRange(self, l: int, r: int) -> int:
        return self.dp[r]-(self.dp[l-1] if l else 0)


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(left,right)