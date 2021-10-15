char* convert(char *s, int numRows){
    if(numRows == 1) return s;
    int L = strlen(s), u = numRows*2-2, idx = 0;
    char *ret = (char*)malloc((L+1)*sizeof(char));
    for(int i = 1; i <= numRows; i++){
        int pos = i-1, step = ((numRows-i)*2+u-1)%u+1;
        while(pos < L){
            ret[idx++] = s[pos];
            pos += step;
            step = (u-step+u-1)%u+1;
        }
    }
    ret[idx] = '\0';
    return ret;
}