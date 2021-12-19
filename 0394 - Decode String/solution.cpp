class Solution {
public:
    int idx = 0;
    string decodeString(string s) {
        string res = "";
        while(idx<s.size() && s[idx]!=']'){
            if(s[idx]>='0' && s[idx]<='9'){
                int n = 0;
                while(s[idx] != '[') n = 10*n+s[idx++]-'0';
                idx++;
                string tmp = decodeString(s);
                idx++;
                while(n--) res += tmp;
            }
            else res += s[idx++];
        }
        return res;
    }
};