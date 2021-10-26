class Solution {
public:
    string reverseWords(string s) {
        string ret = "";
        for(int i = s.size()-1; i >= 0; i--){
            if(s[i] == ' ') continue;
            int id = i;
            while(id>=0 && s[id]!=' ') id--;
            if(ret.size() > 0) ret += " ";
            for(int j = id+1; j <= i; j++) ret += s[j];
            i = id;
        }
        return ret;
    }
};