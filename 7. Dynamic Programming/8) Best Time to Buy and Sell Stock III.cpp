/*
Design an algorithm to find the maximum profit. You may complete at most two transactions.
you must sell the stock before you buy again
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int size = prices.size();
      if (size <= 1) return 0;
    
      vector<int> leftProfits(size, 0), rightProfits(size, 0);
    
      int minLeft = prices[0], maxRight = prices.back();
      for (int i = 1; i < prices.size(); i++){
        // calculate left side profit
        if (prices[i] <= minLeft)   minLeft = prices[i];
        leftProfits[i] = max(prices[i] - minLeft, leftProfits[i-1]);
    
        // calculate right side profit
        int idx = size - i - 1;
        if (prices[idx] > maxRight) maxRight = prices[idx];
        rightProfits[idx] = max(rightProfits[idx + 1], maxRight - prices[idx]);
      }
      int maxProfit = 0;
      for (int i = -1; i < size; i++){
        maxProfit = max(maxProfit,  (i == -1? 0 :leftProfits[i]) + (i == size-1? 0 :rightProfits[i+1]));
      }
      return maxProfit;
    }
};