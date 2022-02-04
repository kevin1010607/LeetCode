class Solution:
    def intToRoman(self, num: int) -> str:
        res, p, t = "", 1, {1000:'M', 500:'D', 100:'C', 50:'L', 10:'X', 5:'V', 1:'I'}
        while num:
            id = (num%10)*p
            while id:
                if id in t:
                    res, id = t[id]+res, 0
                elif id+p in t:
                    res, id = t[p]+t[id+p]+res, 0
                else:
                    res, id = t[p]+res, id-p
            num, p = num//10, p*10
        return res