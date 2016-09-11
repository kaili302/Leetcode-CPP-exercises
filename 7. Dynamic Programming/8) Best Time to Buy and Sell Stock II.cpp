/*
You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
        	return 0;

        int prevMin = prices[0];
        int maxProfit = 0;
        for (int i = 1; i < prices.size(); i++){
        	if (prices[i] > prevMin) 
                maxProfit += prices[i] - prevMin;
       		
        	prevMin = prices[i];
        }
        return maxProfit;
    }
};