class Solution {
public:
    string longestPalindrome(string s) {
        int L = 0, R = 0, l, r;
        for(int i = 0; i < s.size(); i++){
            l = r = i;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > R-L+1) L = l, R = r;
                l--, r++;
            }
            l = i, r = i+1;
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > R-L+1) L = l, R = r;
                l--, r++;
            }
        }
        return s.substr(L, R-L+1);
    }
};