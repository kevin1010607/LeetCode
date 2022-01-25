bool wordPattern(char *pattern, char *s){
    char *p[26] = {};
    int start = 0, pos = 0, end = 0;
    for(int i = 0; !end; i++){
        if(!s[i]) end = 1;
        if(s[i]!=' ' && s[i]!='\0') continue;
        if(!pattern[pos]) return false;
        int id = pattern[pos]-'a';
        s[i] = '\0';
        if(!p[id]){
            for(int j = 0; j < 26; j++)
                if(p[j] && !strcmp(p[j], s+start)) return false;
            p[id] = s+start;
        }
        else if(strcmp(p[id], s+start)) return false;
        start = i+1, pos++;
    }
    return !pattern[pos];
}