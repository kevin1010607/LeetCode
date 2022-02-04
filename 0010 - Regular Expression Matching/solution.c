bool isMatch(char * s, char * p){
    for(char c = *p; c; s++, c = *p){
        if(*(p+1) != '*') p++;
        else if (isMatch(s, p+2)) return true;
        if(!*s || (c!='.'&&c!=*s)) return false;
    }
    return !*s;
}