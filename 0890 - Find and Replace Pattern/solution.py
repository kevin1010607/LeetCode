class Solution:
    def findAndReplacePattern(self, A: List[str], p: str) -> List[str]:
        return list(s for s in A if len(set(s)) == len(set(p)) == len(set(zip(s, p))))