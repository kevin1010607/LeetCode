class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()
        def solve(idx, need, now):
            if need == 0:
                res.append(now[:])
                return
            for i in range(idx, len(candidates)):
                if i>idx and candidates[i]==candidates[i-1]:
                    continue
                if candidates[i] > need:
                    break
                now.append(candidates[i])
                solve(i+1, need-candidates[i], now)
                now.pop()
        solve(0, target, [])
        return res
            