from itertools import accumulate
class Solution:
    def runningSum(self, A: List[int]) -> List[int]:
        return list(accumulate(A))