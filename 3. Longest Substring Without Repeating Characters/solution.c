 #define max(a,b) a>b?a:b
int lengthOfLongestSubstring(char *s){
    int start = 0, idx = 0, ret = 0, map[128];
    memset(map, -1, sizeof(map));
    while(s[idx]){
        if(map[s[idx]] != -1) start = max(map[s[idx]]+1, start);
        ret = max(ret, idx-start+1);
        map[s[idx]] = idx;
        idx++;
    }
    return ret;
}
