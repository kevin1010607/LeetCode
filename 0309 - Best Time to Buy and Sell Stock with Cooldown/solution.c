#define max(a,b) a>b?a:b
int maxProfit(int *prices, int pricesSize){
    int cool = 0, buy = -prices[0], sell = 0;
    for(int i = 1; i < pricesSize; i++){
        int tmp = sell;
        sell = buy+prices[i];
        buy = max(buy, cool-prices[i]);
        cool = max(cool, tmp);
    }
    return max(cool, sell);
}