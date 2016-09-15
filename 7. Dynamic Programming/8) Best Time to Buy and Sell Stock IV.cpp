/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete at most k transactions.
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
    	int daysNum = prices.size();
    	if (daysNum <= 1) 
    		return 0;

    	// dp[i][j] means max profit with at most j transactions during first i days
    	vector<vector<int>> dp(daysNum + 1, vector<int>(k + 1));
    	for (int j = 1; j <= k; j++){
    		int tmpMin = INT_MAX;
	    	for (int i = 1; i <= daysNum; i++){
	    		dp[i][j] = max(dp[i][j-1], prices[i] - tmpMin);
	    		tmpMin = min(tmpMin, prices[i] - dp[i][j-1]);
	    	}	
    	}
    	return dp[daysNum][k];
    }
};