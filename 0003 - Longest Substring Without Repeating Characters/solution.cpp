class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0, start = 0;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++){
            if(m.count(s[i])) start = max(start, m[s[i]]+1);
            res = max(res, i-start+1), m[s[i]] = i;
        }
        return res;
    }
};