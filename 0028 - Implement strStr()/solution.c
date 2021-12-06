int strStr(char * haystack, char * needle){
    char *pos = strstr(haystack, needle);
    return pos?pos-haystack:-1;
}
