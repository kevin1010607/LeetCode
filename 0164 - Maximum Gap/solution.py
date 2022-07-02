class Solution:
    def maximumGap(self, A: List[int]) -> int:
        _min, _max = min(A), max(A)
        bktSz = max(1, (_max-_min)//len(A))
        bkt = [(inf, -inf) for _ in range((_max-_min)//bktSz+1)]
        for i in A:
            idx = (i-_min)//bktSz
            bkt[idx] = (min(bkt[idx][0], i), max(bkt[idx][1], i))
        res, prev = 0, _min
        for i, j in bkt:
            if i != inf and j != -inf:
                res, prev = max(res, i-prev), j
        return res