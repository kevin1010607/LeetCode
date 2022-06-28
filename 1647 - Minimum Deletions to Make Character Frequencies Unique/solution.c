#define max(a,b) (((a)>(b))?(a):(b))
int cmp(const void *a, const void *b){
    return *(const int*)a-*(const int*)b;
}
int minDeletions(char * s){
    int res = 0, cnt[26] = {};
    for(int i = 0; s[i]; i++) cnt[s[i]-'a']++;
    qsort(cnt, 26, sizeof(int), cmp);
    for(int i = 24; i >= 0; i--){
        if(cnt[i] == 0) break;
        if(cnt[i] >= cnt[i+1]){
            int prev = cnt[i];
            cnt[i] = max(0, cnt[i+1]-1);
            res += prev-cnt[i];
        }
    }
    return res;
}