class Solution {
public:
    int maxPower(string s) {
        int res = 1, now = 1;
        for(int i = 1; i < s.size(); i++){
            now = s[i]==s[i-1]?now+1:1;
            res = max(res, now);
        }
        return res;
    }
};