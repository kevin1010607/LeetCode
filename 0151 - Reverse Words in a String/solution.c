char* reverseWords(char *s){
    int L = strlen(s);
    char *ret = (char*)calloc(L+1, sizeof(char));
    for(int i = L-1, first = 1; i >= 0; i--){
        if(s[i] == ' ') continue;
        int id = i;
        while(id>=0 && s[id]!=' ') id--;
        if(!first) strncat(ret, " ", 1);
        strncat(ret, s+id+1, i-id);
        i = id, first = 0;
    }
    return ret;
}