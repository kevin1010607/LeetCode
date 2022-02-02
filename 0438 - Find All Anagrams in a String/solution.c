/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char * s, char * p, int* returnSize){
    int *res = (int*)malloc(30005*sizeof(int));
    int idx = 0, val = 0, t[26] = {}, i, j;
    for(i = 0; p[i]; i++) if(t[p[i]-'a']++ == 0) val++;
    for(j = 0; s[j]; j++){
        if(j >= i) if(t[s[j-i]-'a']++ == 0) val++;
        if(--t[s[j]-'a'] == 0) val--;
        if(val == 0) res[idx++] = j-i+1;
    }
    *returnSize = idx;
    res = realloc(res, idx*sizeof(int));
    return res;
}