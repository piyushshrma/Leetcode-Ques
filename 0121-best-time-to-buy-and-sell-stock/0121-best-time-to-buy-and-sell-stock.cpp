class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buyDay=prices[0];
        int profit=0;
        for(int sellDay=1; sellDay<prices.size(); sellDay++){
            profit=max(profit, prices[sellDay]-buyDay);
            buyDay=min(buyDay, prices[sellDay]);
        }
        return profit;
    }
};