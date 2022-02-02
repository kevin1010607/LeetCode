class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> t1(26), t2(26);
        for(auto i : s) t1[i-'a']++;
        for(auto i : t) t2[i-'a']++;
        for(int i = 0; i < 26; i++)
            if(t1[i] != t2[i]) return false;
        return true;
    }
};