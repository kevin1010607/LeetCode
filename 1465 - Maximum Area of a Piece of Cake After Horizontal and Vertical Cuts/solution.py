class Solution:
    def maxArea(self, h: int, w: int, hc: List[int], vc: List[int]) -> int:
        def maxGap(A, sz):
            A = [0]+sorted(A)+[sz]
            return max(A[i+1]-A[i] for i in range(len(A)-1))
        return maxGap(hc, h)*maxGap(vc, w)%int(1e9+7)