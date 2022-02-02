void expand(char *s, int l, int r, int *L, int *R){
    while(l>=0 && s[r] && s[l]==s[r]){
        if(r-l+1 > *R-*L+1) *L = l, *R = r;
        l--, r++;
    }
}
char * longestPalindrome(char * s){
    int L = 0, R = 0;
    for(int i = 0; s[i]; i++){
        expand(s, i, i, &L, &R);
        expand(s, i, i+1, &L, &R);
    }
    char *res = (char*)calloc(R-L+2, sizeof(char));
    strncpy(res, s+L, R-L+1);
    return res;
}