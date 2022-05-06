class Solution {
public:
    string removeDuplicates(string s) {
        int idx = 0;
        for(int i = 0; i < s.size(); i++, idx++){
            s[idx] = s[i];
            if(idx>0 && s[idx-1]==s[idx]) idx -= 2;
        }
        return s.substr(0, idx);
    }
};