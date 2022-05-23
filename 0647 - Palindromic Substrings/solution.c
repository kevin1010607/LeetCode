int countSubstrings(char *s){
    int res = 1, l, r;
    for(int i = 1; s[i]; i++){
        l = r = i, res++;
        while(l-1>=0 && s[r+1] && s[l-1]==s[r+1]) res++, l--, r++;
        l = i, r = i-1;
        while(l-1>=0 && s[r+1] && s[l-1]==s[r+1]) res++, l--, r++;
    }
    return res;
}