#define max(a,b) (((a)>(b))?(a):(b))
int maxProfit(int* prices, int pricesSize, int fee){
    int s1 = 0, s2 = -prices[0], ns1, ns2;
    for(int i = 1; i < pricesSize; i++){
        ns1 = max(s1, s2+prices[i]-fee);
        ns2 = max(s2, s1-prices[i]);
        s1 = ns1, s2 = ns2;
    }
    return s1;
}