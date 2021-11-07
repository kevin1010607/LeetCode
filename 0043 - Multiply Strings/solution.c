char* multiply(char *num1, char *num2){
    if(!strcmp(num1, "0") || !strcmp(num2, "0")){
        char *ret = (char*)malloc(2*sizeof(char));
        ret[0] = '0', ret[1] = '\0';
        return ret;
    }
    int n1 = strlen(num1), n2 = strlen(num2);
    int *v = (int*)calloc(n1+n2, sizeof(int));
    for(int i = n1-1; i >= 0; i--){
        for(int j = n2-1; j >= 0; j--){
            v[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
            v[i+j] += v[i+j+1]/10;
            v[i+j+1] %= 10;
        }
    }
    int id = 0;
    while(v[id] == 0) id++;
    char *ret = (char*)malloc((n1+n2-id+1)*sizeof(char));
    for(int i = 0; i < n1+n2-id; i++) ret[i] = '0'+v[i+id];
    ret[n1+n2-id] = '\0';
    free(v);
    return ret;
}