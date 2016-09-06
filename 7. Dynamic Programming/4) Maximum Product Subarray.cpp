/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*/

class Solution{
public:
	int maxProduct(vector<int> nums) {
		if (nums.empty()) return 0;
		int currMin = nums[0];
		int currMax = nums[0];
		int maxProduct = currMax;
		for (int i = 1; i < nums.size(); i++){
		    int tmp = currMax;
			currMax = max(max(currMax * nums[i], currMin * nums[i]), nums[i]);
			currMin = min(min(tmp * nums[i], currMin * nums[i]), nums[i]);
			maxProduct = max(maxProduct, currMax);
		}
		return maxProduct;
	}
};