#define max(a,b) (((a)>(b))?(a):(b))
#define min(a,b) (((a)<(b))?(a):(b))
int maxProfit(int* prices, int pricesSize){
    int res = 0, now = 10005;
    for(int i = 0; i < pricesSize; i++){
        res = max(res, prices[i]-now);
        now = min(now, prices[i]);
    }
    return res;
}