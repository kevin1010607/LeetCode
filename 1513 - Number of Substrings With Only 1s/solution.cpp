class Solution {
public:
    const int MOD = 1e9+7;
    int numSub(string s) {
        long long res = 0, now = 0;
        for(char c : s){
            now = c=='1'?now+1:0;
            res = (res+now)%MOD;
        }
        return (int)res;
    }
};