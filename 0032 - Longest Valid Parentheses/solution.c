#define max(a,b) (((a)>(b))?(a):(b))
int longestValidParentheses(char *s){
    int res = 0, l = 0, r = 0, i;
    for(i = 0; s[i]; i++){
        s[i]=='('?l++:r++;
        if(l == r) res = max(res, l+r);
        if(r > l) l = r = 0;
    }
    l = r = 0;
    for(i = i-1; i >= 0; i--){
        s[i]=='('?l++:r++;
        if(l == r) res = max(res, l+r);
        if(l > r) l = r = 0;
    }
    return res;
}