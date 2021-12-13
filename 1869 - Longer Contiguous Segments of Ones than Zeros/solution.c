#define max(a,b) a>b?a:b
bool checkZeroOnes(char *s){
    int l1 = 0, l2 = 0, now = 1;
    s[0]=='1'?l1++:l2++;
    for(int i = 1; s[i]; i++){
        now = s[i]==s[i-1]?now+1:1;
        if(s[i] == '1') l1 = max(l1, now);
        else l2 = max(l2, now);
    }
    return l1>l2;
}