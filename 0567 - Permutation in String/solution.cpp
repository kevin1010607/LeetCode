class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), val = 0, t[26] = {};
        for(auto i : s1) if(t[i-'a']++ == 0) val++;
        for(int i = 0; i < s2.size(); i++){
            if(i>=n && t[s2[i-n]-'a']++==0) val++;
            if(--t[s2[i]-'a'] == 0) val--;
            if(val == 0) return true;
        }
        return false;
    }
};