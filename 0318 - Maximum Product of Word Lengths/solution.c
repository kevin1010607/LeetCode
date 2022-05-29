#define max(a,b) (((a)>(b))?(a):(b))
int maxProduct(char ** A, int n){
    int res = 0, m[1001] = {}, len[1001] = {}, l;
    for(int i = 0; i < n; i++){
        for(l = 0; A[i][l]; l++) m[i] |= 1<<(A[i][l]-'a');
        len[i] = l;
        for(int j = 0; j < i; j++)
            if(!(m[i] & m[j])) res = max(res, len[i]*len[j]);
    }
    return res;
}