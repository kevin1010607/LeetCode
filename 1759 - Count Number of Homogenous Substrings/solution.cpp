class Solution {
public:
    const int MOD = 1e9+7;
    int countHomogenous(string s) {
        long long res = 1, now = 1;
        for(int i = 1; i < s.size(); i++){
            now = s[i]==s[i-1]?now+1:1;
            res = (res+now)%MOD;
        }
        return (int)res;
    }
};