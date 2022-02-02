bool isAnagram(char * s, char * t){
    int t1[26] = {}, t2[26] = {};
    for(int i = 0; s[i]; i++) t1[s[i]-'a']++;
    for(int i = 0; t[i]; i++) t2[t[i]-'a']++;
    for(int i = 0; i < 26; i++)
        if(t1[i] != t2[i]) return false;
    return true;
}