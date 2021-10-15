class Solution{
public:
    int maxProfits(vector<int> &prices){
        int cool(0), buy(INT_MIN), sell(0);
        for(int price : prices){
            int tmp(sell);
            sell = buy+price;
            buy = max(buy, cool-price);
            cool = max(cool, tmp);
        }
        return max(sell, cool);
    }
};