class Solution:
    def uniqueMorseRepresentations(self, A: List[str]) -> int:
        m = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        return len(set((''.join(m[ord(c)-ord('a')] for c in s) for s in A)))