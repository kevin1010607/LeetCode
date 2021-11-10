#define max(a,b) a>b?a:b
int maxProfit(int* prices, int pricesSize){
    int profit = 0;
    for(int i = 1; i < pricesSize; i++) profit += max(prices[i]-prices[i-1], 0);
    return profit;
}