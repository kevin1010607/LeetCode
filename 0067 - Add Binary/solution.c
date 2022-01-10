int max(int a, int b) {return a>b?a:b;}
char* addBinary(char *a, char *b){
    int i = strlen(a)-1, j = strlen(b)-1, idx = 0;
    char *res = (char*)malloc((max(i, j)+3)*sizeof(char));
    for(int c = 0; i>=0||j>=0||c; i--, j--, c/=2){
        if(i >= 0) c += a[i]-'0';
        if(j >= 0) c += b[j]-'0';
        res[idx++] = '0'+(c%2);
    }
    for(int i = 0, j = idx-1; i < j; i++, j--){
        char c = res[i];
        res[i] = res[j], res[j] = c;
    }
    res[idx] = '\0';
    return res;
}