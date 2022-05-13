class Solution:
    def isAlienSorted(self, A: List[str], order: str) -> bool:
        m = {c: i for i, c in enumerate(order)}
        A = [[m[i] for i in s] for s in A]
        return all(s1 <= s2 for s1, s2 in zip(A, A[1:]))