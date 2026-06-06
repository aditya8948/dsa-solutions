class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit= 0 , n = prices.size();
        for(int i = 0 ; i < n-1; i++){
            if(prices[i] < prices[i+1]){
                int j = i+1;
                while(j < n-1 && prices[j] < prices[j+1]) j++;
                profit  += prices[j] - prices[i];
                i = j-1;
            }
        }
        return profit;
    }
};