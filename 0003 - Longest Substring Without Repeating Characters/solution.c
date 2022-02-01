#define max(a,b) (((a)>(b))?(a):(b))
int lengthOfLongestSubstring(char * s){
    int res = 0, start = 0, m[128];
    memset(m, 0xff, sizeof(m));
    for(int i = 0; s[i]; i++){
        if(m[s[i]] != -1) start = max(start, m[s[i]]+1);
        res = max(res, i-start+1), m[s[i]] = i;
    }
    return res;
}