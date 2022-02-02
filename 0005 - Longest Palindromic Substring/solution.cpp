class Solution {
public:
    string longestPalindrome(string s) {
        int L = 0, R = 0;
        auto expand = [&](int l, int r){
            while(l>=0 && r<s.size() && s[l]==s[r]){
                if(r-l+1 > R-L+1) L = l, R = r;
                l--, r++;
            }
        };
        for(int i = 0; i < s.size(); i++){
            expand(i, i);
            expand(i, i+1);
        }
        return s.substr(L, R-L+1);
    }
};