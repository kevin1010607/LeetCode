char* longestPalindrome(char *s){
    int L = 0, R = 0, idx = 0, l, r;
    while(s[idx]){
        l = r = idx;
        while(l>=0 && s[l]==s[r]){
            if(r-l+1 > R-L+1) L = l, R = r;
            l--, r++;
        }
        l = idx, r = idx+1;
        while(l>=0 && s[l]==s[r]){
            if(r-l+1 > R-L+1) L = l, R = r;
            l--, r++;
        }
        idx++;
    }
    char *ret = (char*)malloc((R-L+2)*sizeof(char));
    strncpy(ret, s+L, R-L+1);
    ret[R-L+1] = '\0';
    return ret;
}