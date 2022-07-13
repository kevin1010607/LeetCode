class Solution:
    def makesquare(self, A):
        @lru_cache(None)
        def dp(mask):
            for i in range(n):
                if mask & 1<<i:
                    rm = dp(mask^(1<<i))
                    if rm >= 0 and rm+A[i] <= tar:
                        return (rm+A[i])%tar
            return -1 if mask else 0
        n, tar = len(A), sum(A)//4
        return False if sum(A)%4 else dp((1<<n)-1) == 0