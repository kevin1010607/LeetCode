class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        m = {'2':'abc','3':'def','4':'ghi','5':'jkl',
            '6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        res = [''] if digits else []
        for i in digits:
            res = [p+q for p in res for q in m[i]]
        return res