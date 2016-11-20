/*
There are N children standing in a line. Each child is assigned a rating value. 
You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?
*/

class Solution{
public:
	int candy(vector<int>& rating){
		if (rating.empty()) return 0;
		vector<int> candies(rating.size());
		candies[0] = 1;
		for (int i = 1; i < rating.size(); i++){
			if (rating[i] > rating[i-1]) candies[i] = candies[i-1] + 1;
			else candies[i] = 1;
		}
		int totalCandies = candies.back();
		for (int i = rating.size() - 2; i >= 0; i--){
			if (rating[i] > rating[i+1]) candies[i] = max(candies[i+1] + 1, candies[i]);
			totalCandies += candies[i];
		}
		return totalCandies;
	}
};