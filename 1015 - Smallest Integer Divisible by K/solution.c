int smallestRepunitDivByK(int k){
    if(!(k%2) || !(k%5)) return -1;
    int r = 1%k, res = 1;
    while(r){
        r = (10*r+1)%k;
        res++;
    }
    return res;
}