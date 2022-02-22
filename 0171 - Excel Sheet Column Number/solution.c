int titleToNumber(char * columnTitle){
    int res = 0;
    for(int i = 0; columnTitle[i]; i++) res = 26*res+(columnTitle[i]-'A'+1);
    return res;
}