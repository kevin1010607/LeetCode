#define MOD (int)(1e9+7)
int numSub(char *s){
    long long res = 0, now = 0;
    for(int i = 0; s[i]; i++){
        now = s[i]=='1'?now+1:0;
        res = (res+now)%MOD;
    }
    return (int)res;
}