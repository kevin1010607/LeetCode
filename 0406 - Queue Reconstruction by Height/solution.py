class Solution:
    def reconstructQueue(self, A: List[List[int]]) -> List[List[int]]:
        A.sort(key=lambda x: (-x[0], x[1]))
        res = []
        for i in A:
            res.insert(i[1], i)
        return res