class Solution:
    def merge(self, A: List[List[int]]) -> List[List[int]]:
        res = []
        for l, r in sorted(A):
            if res and l <= res[-1][1]:
                res[-1][1] = max(res[-1][1], r)
            else:
                res.append([l, r])
        return res