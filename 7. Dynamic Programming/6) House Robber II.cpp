/*
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a circle.  That means the first house is 
the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 money you can rob tonight without alerting the police.
*/
class Solution {
public:
	int rob(vector<int>& nums, int lo, int hi){
		int robMax = 0;
		int skipMax = 0;
		for (int i = lo; i <= hi; i++){
			int tmp = robMax;
			robMax = skipMax + nums[i];
			skipMax = max(skipMax, tmp);
		}
		return max(robMax, skipMax);
	}

	int rob(vector<int>& nums) {
		if (nums.empty()) return 0;
		if (nums.size() == 1) return nums.back();
		return max(rob(nums, 0, nums.size() - 2), rob(nums, 1, nums.size()-1));
	}
};