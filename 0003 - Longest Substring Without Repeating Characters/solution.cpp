class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, start = 0;
        unordered_map<char, int> table;
        for(int i = 0; i < s.size(); i++){
            if(table.find(s[i]) != table.end()) start = max(start, table[s[i]]+1);
            table[s[i]] = i;
            ret = max(ret, i-start+1);
        }
        return ret;
    }
};
