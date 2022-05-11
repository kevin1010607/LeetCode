class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        res = [[]]
        for _ in range(k):
            res = [[i]+j for j in res for i in range(1, j[0] if j else 10)]
        return [i for i in res if sum(i) == n]