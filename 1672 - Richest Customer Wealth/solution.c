#define max(a,b) (((a)>(b))?(a):(b))
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize){
    int res = 0, m = accountsSize, n = *accountsColSize;
    for(int i = 0; i < m; i++){
        int now = 0;
        for(int j = 0; j < n; j++) now += accounts[i][j];
        res = max(res, now);
    }
    return res;
}