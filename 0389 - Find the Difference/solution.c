char findTheDifference(char * s, char * t){
    int i;
    for(i = 0; s[i]; i++) t[i+1] += t[i]-s[i];
    return t[i];
}