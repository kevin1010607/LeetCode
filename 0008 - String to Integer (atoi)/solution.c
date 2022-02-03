int myAtoi(char * s){
    int res = 0, sign = 1, i = 0;
    while(s[i] == ' ') i++;
    if(s[i]=='+' || s[i]=='-') sign = s[i++]=='+'?1:-1;
    while(s[i]>='0' && s[i]<='9'){
        if(res>INT_MAX/10 || (res==INT_MAX/10&&s[i]>'7')) return sign==1?INT_MAX:INT_MIN;
        res = 10*res+(s[i++]-'0');
    }
    return sign*res;
}