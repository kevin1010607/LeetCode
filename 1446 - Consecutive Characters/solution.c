int maxPower(char *s){
    int res = 1, now = 1;
    for(int i = 1; s[i]; i++){
        now = s[i]==s[i-1]?now+1:1;
        res = res>now?res:now;
    }
    return res;
}