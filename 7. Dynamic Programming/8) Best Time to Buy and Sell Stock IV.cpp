/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete at most k transactions.
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
    	int size = prices.size();
    	if (prices.size() <= 1) 
    		return 0;

    	// dp[i][j] means max profit within i days with j transactions
    	vector<vector<int>> dp(size + 1, vector<int>(k + 1));



        
    }
};