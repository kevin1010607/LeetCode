class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> m(128, -1);
        int res = 0, start = 0;
        for(int i = 0; i < s.size(); i++){
            if(m[s[i]] != -1) start = max(start, m[s[i]]+1);
            res = max(res, i-start+1), m[s[i]] = i;
        }
        return res;
    }
};