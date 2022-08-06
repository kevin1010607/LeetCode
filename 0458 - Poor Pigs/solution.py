class Solution:
    def poorPigs(self, buckets: int, die: int, test: int) -> int:
        n, res = test/die+1, 0
        while n**res < buckets:
            res += 1
        return res