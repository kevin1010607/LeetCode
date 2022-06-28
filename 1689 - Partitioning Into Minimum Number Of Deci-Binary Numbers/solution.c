#define max(a,b) (((a)>(b))?(a):(b))
int minPartitions(char * n){
    int res = 0;
    while(*n) res = max(res, *n-'0'), n++;
    return res;
}