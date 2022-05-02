class Solution {
private:
    int enter(string& s){
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#') idx = max(0, idx-1);
            else s[idx++] = s[i];
        }
        return idx;
    }
public:
    bool backspaceCompare(string s1, string s2) {
        int n1 = enter(s1), n2 = enter(s2);
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++)
            if(s1[i] != s2[i]) return false;
        return true;
    }
};