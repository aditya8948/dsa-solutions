class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1 ; i < prices.size() ;i++){
            minPrice = min(prices[i] , minPrice);        // update buying price  
            maxProfit = max(maxProfit, prices[i] - minPrice); // update max profit value
            
        }
        return maxProfit;
    }
};