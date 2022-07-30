import operator
from collections import Counter
class Solution:
    def wordSubsets(self, A: List[str], B: List[str]) -> List[str]:
        cnt = reduce(operator.or_, (Counter(s) for s in B))
        return list(s for s in A if not cnt-Counter(s))