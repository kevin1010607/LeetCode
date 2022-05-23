class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), res = 0, l = 0, r = 0, i, j;
        while(r < n){
            while(r<n && s[l]==s[r]) r++;
            res += (r-l)*(r-l+1)/2;
            i = l-1, j = r;
            while(i>=0 && j<n && s[i]==s[j]) i--, j++, res++;
            l = r;
        }
        return res;
    }
};