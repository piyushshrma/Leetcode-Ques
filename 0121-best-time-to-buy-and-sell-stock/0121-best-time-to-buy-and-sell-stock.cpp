class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int bestBuy=prices[0];
        for(int i=1; i<prices.size(); i++){
            bestBuy=min(bestBuy, prices[i]);
            profit=max(profit, prices[i]-bestBuy);
        }
        return profit;
    }
};