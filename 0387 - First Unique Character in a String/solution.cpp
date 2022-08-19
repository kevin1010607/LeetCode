class Solution {
public:
    int firstUniqChar(string s) {
        int res = INT_MAX;
        unordered_map<char, int> m;
        for(int i = 0; i < s.size(); i++)
            m[s[i]] = m.count(s[i])?INT_MAX:i;
        for(auto [i, v] : m)
            res = min(res, v);
        return res==INT_MAX?-1:res;
    }
};