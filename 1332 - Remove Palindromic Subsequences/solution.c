int removePalindromeSub(char *s){
    int l = 0, r = strlen(s)-1;
    while(l < r)
        if(s[l++] != s[r--]) return 2;
    return 1;
}