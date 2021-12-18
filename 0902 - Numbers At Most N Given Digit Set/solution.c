int atMostNGivenDigitSet(char **digits, int digitsSize, int n){
    char num[15];
    sprintf(num, "%d", n);
    int d = digitsSize, m = strlen(num), res = 0;
    for(int i = 1; i < m; i++) res += pow(d, i);
    for(int i = 0; i < m; i++){
        bool e = false;
        for(int j = 0; j < d; j++){
            if(digits[j][0] < num[i]) res += pow(d, m-i-1);
            else if(digits[j][0] == num[i]) e = true;
        }
        if(!e) return res;
    }
    return res+1;
}