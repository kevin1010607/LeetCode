#define N (1<<20)
bool hasAllCodes(char *s, int k){
    bool v[N] = {};
    int key = 0, cnt = 1<<k;
    for(int i = 0; s[i]; i++){
        key = (key>>1)|((s[i]-'0')<<(k-1));
        if(i>=k-1 && !v[key]) v[key] = true, cnt--;
    }
    return !cnt;
}