char * longestCommonPrefix(char ** strs, int strsSize){
    int flag = 1, len = 0;
    for(int i = 0; flag && strs[0][i]; i++){
        for(int j = 0; j < strsSize; j++)
            if(!strs[j][i] || strs[j][i]!=strs[0][i]) {flag = 0; break;}
        if(flag) len++;
    }
    char *res = (char*)calloc(len+1, sizeof(char));
    strncpy(res, strs[0], len);
    return res;
}