int romanToInt(char * s){
    int t[26] = {};
    t['I'-'A']=1,t['V'-'A']=5,t['X'-'A']=10,t['L'-'A']=50;
    t['C'-'A']=100,t['D'-'A']=500,t['M'-'A']=1000;
    int res = t[s[0]-'A'];
    for(int i = 1; s[i]; i++){
        res += t[s[i]-'A'];
        if(t[s[i]-'A'] > t[s[i-1]-'A']) res -= 2*t[s[i-1]-'A'];
    }
    return res;
}