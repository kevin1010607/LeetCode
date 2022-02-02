class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = p.size(), val = 0;
        vector<int> res, t(26);
        for(auto i : p) if(t[i-'a']++ == 0) val++;
        for(int i = 0; i < s.size(); i++){
            if(i >= n) if(t[s[i-n]-'a']++ == 0) val++;
            if(--t[s[i]-'a'] == 0) val--;
            if(val == 0) res.push_back(i-n+1);
        }
        return res;
    }
};