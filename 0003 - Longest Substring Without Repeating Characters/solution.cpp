class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int l = 0, r = 0, res = 0;
        for(int r = 0; r < s.size(); r++){
            if(m[s[r]] != -1) l = max(l, m[s[r]]+1);
            res = max(res, r-l+1), m[s[r]] = r;
        }
        return res;
    }
};