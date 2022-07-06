class Solution:
    @lru_cache(None)
    def fib(self, n: int) -> int:
        return n if 0 <= n <= 1 else self.fib(n-1)+self.fib(n-2);