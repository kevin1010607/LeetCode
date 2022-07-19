class Solution:
    def generate(self, n: int) -> List[List[int]]:
        res = [[1]]
        for i in range(1, n):
            res.append(list(map((lambda x, y: x+y), res[-1]+[0], [0]+res[-1])))
        return res