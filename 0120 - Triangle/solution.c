#define INF 0x3f3f3f3f
#define min(a,b) (((a)<(b))?(a):(b))
int minimumTotal(int** A, int sz, int* colSz){
    for(int i = 1; i < sz; i++)
        for(int j = 0; j <= i; j++)
            A[i][j] += min(j!=0?A[i-1][j-1]:INF, j!=i?A[i-1][j]:INF);
    int res = INF;
    for(int i = 0; i < sz; i++) res = min(res, A[sz-1][i]);
    return res;
}