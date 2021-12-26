int calculate(char *s){
    char pre = '+';
    int now = 0, mid = 0, ans = 0;
    for(int i = 0; ; i++){
        if(isspace(s[i])) continue;
        if(isdigit(s[i])){
            now = 0;
            while(isdigit(s[i])) now = 10*now+(s[i++]-'0');
            i--;
        }
        else{
            if(pre == '*') mid *= now;
            else if(pre == '/') mid /= now;
            else ans += mid, mid = pre=='+'?now:-now;
            pre = s[i];
        }
        if(s[i] == '\0') break;
    }
    return ans+mid;
}