class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        from itertools import combinations
        res, n, p, z = set(), [], [], 0
        for i in nums:
            if i < 0:
                n.append(i)
            elif i > 0:
                p.append(i)
            else:
                z += 1
        N, P = set(n), set(p)
        if z:
            for i in n:
                if -i in P:
                    res.add((-i, 0, i))
            if z >= 3:
                res.add((0, 0, 0))
        for x, y in combinations(n, 2):
            if -x-y in P:
                res.add(tuple(sorted([x, y, -x-y])))
        for x, y in combinations(p, 2):
            if -x-y in N:
                res.add(tuple(sorted([x, y, -x-y])))
        return map(list, res)