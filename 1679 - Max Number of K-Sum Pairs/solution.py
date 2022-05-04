class Solution:
    def maxOperations(self, A: List[int], k: int) -> int:
        c = Counter(A);
        return sum(min(c[i], c[k-i]) for i in c)//2