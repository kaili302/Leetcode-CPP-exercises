/*
Say you have an array for which the ith element is the price of a given stock on day i.
Design an algorithm to find the maximum profit. 
You may complete at most k transactions.
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int profit = 0;
        for (int i = 1; i < prices.size(); i++){
            if (prices[i] > prices[i-1]) profit += prices[i] - prices[i-1];
        }
        return profit;
    }

    int maxProfit(int m, vector<int>& prices){
        int size = prices.size();
        if (size <= 1) return 0;
        if (m > size/2) 
            return maxProfit(prices);
        vector<vector<int>> dp(size, vector<int>(m+1, 0));
        for (int k = 1; k <= m; k++){
            int maxCapital = -prices[0];
            for (int i = 1; i < size; i++){
                dp[i][k] = max(dp[i-1][k], maxCapital + prices[i]);
                maxCapital = max(maxCapital, dp[i][k-1] - prices[i]);
            }
        }
        return dp[size-1][m];
    }
};