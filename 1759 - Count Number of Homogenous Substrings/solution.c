#define MOD (int)(1e9+7)
int countHomogenous(char *s){
    long long res = 1, now = 1;
    for(int i = 1; s[i]; i++){
        now = s[i]==s[i-1]?now+1:1;
        res = (res+now)%MOD;
    }
    return (int)res;
}