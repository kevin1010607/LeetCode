class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        from collections import deque
        from string import ascii_lowercase
        res, d, q = 1, set(wordList), deque([beginWord])
        while q:
            n = len(q)
            for _ in range(n):
                s = q.popleft()
                if s == endWord:
                    return res
                for i in range(len(s)):
                    for j in ascii_lowercase:
                        now = s[:i]+j+s[i+1:]
                        if now in d:
                            d.remove(now)
                            q.append(now)
            res += 1
        return 0