/*
Design an algorithm to find the maximum profit. You may complete at most two transactions.
you must sell the stock before you buy again
*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
    	int size = prices.size();
    	if (size <= 1) return 0;

    	vector<int> maxProfitLeft(size, 0);
    	vector<int> maxProfitRight(size, 0);

    	int leftPrevMin = prices[0];
    	int rightPrevMax = prices[size-1];

    	for (int i = 1; i < size; i++){
    		if (leftPrevMin > prices[i]) {
    			leftPrevMin = prices[i];
    			maxProfitLeft[i] = maxProfitLeft[i-1];
    		}else
    			maxProfitLeft[i] = max(prices[i] - leftPrevMin, maxProfitLeft[i-1]);

    		int j = size - 1 - i;
    		if (rightPrevMax < prices[j]){
    			rightPrevMax = prices[j];
    			maxProfitRight[j] = maxProfitRight[j+1];
    		}else
    			maxProfitRight[j] = max(maxProfitRight[j+1], rightPrevMax - prices[j]);
      	}

      	int maxProfit = 0;
      	for (int i = 0; i < size; i++){
      		maxProfit = max(maxProfit, maxProfitLeft[i] + maxProfitRight[i]);
      	}
      	return maxProfit;
    }
};