class Solution:
    def kInversePairs(self, n: int, k: int) -> int:
        dp1, dp2, MOD = [1]+[0]*k, [0]*(k+1), int(1e9+7)
        for i in range(2, n+1):
            dp2[0] = 1
            for j in range(1, k+1):
                dp2[j] = MOD-dp1[j-i] if j >= i else 0
                dp2[j] = (dp2[j]+dp2[j-1]+dp1[j])%MOD
            dp1, dp2 = dp2, dp1
        return dp1[k]%MOD