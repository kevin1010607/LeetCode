#define min(a,b) (((a)<(b))?(a):(b))
int firstUniqChar(char * s){
    int A[26], res = INT_MAX;
    memset(A, 0xff, sizeof(A));
    for(int i = 0; s[i]; i++)
        A[s[i]-'a'] = A[s[i]-'a']==-1?i:INT_MAX;
    for(int i = 0; i < 26; i++)
        if(A[i] != -1) res = min(res, A[i]);
    return res==INT_MAX?-1:res;
}