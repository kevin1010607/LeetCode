char * minWindow(char * s, char * t){
    int m[128] = {}, l = 0, r = 0, start = -1, len = INT_MAX, cnt = 0;
    for(cnt = 0; t[cnt]; cnt++) m[t[cnt]]++;
    for(r = 0; s[r]; r++){
        if(m[s[r]]-- > 0) cnt--;
        while(cnt == 0){
            if(r-l+1 < len) len = r-l+1, start = l;
            if(m[s[l++]]++ == 0) cnt++;
        }
    }
    if(start == -1) return "";
    char *res = (char*)calloc(len+1, sizeof(char));
    strncpy(res, s+start, len);
    return res;
}