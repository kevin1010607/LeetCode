class Solution:
    def findMinMoves(self, A: List[int]) -> int:
        total, n = sum(A), len(A)
        if total%n:
            return -1
        target, move, res = total//n, 0, 0
        for i in A:
            move += i-target
            res = max(res, abs(move), i-target)
        return res