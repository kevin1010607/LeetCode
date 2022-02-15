class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def generate(p, left, right):
            if right >= left >= 0:
                if not left and not right:
                    yield p
                yield from generate(p+'(', left-1, right)
                yield from generate(p+')', left, right-1)
        return list(generate('', n, n))
                