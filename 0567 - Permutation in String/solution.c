bool checkInclusion(char * s1, char * s2){
    int val = 0, t[26] = {}, i, j;
    for(i = 0; s1[i]; i++) if(t[s1[i]-'a']++ == 0) val++;
    for(j = 0; s2[j]; j++){
        if(j>=i && t[s2[j-i]-'a']++==0) val++;
        if(--t[s2[j]-'a']==0) val--;
        if(val == 0) return true;
    }
    return false;
}