bool isMatch(char * s, char * p){
    int i = 0, j = 0, si = -1, pi = -1;
    while(s[i]){
        if(p[j]=='*' && !p[j+1]) return true;
        else if(p[j] == '*') si = i, pi = ++j;
        else if(p[j]=='?' || p[j]==s[i]) i++, j++;
        else if(pi != -1) i = ++si, j = pi;
        else return false;
    }
    while(p[j] == '*') j++;
    return !p[j];
}