/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
the only constraint stopping you from robbing each of them is that adjacent houses have security system connected 
and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you 
can rob tonight without alerting the police.
*/
class Solution{
public:
 	int rob(vector<int>& nums) {
 		if (nums.empty()) return 0;
 		int robThisMax = nums[0];
 		int skipThisMax = 0;
 		for (int i = 1; i < nums.size(); i++){
 			int swap = robThisMax;
 			robThisMax = max(robThisMax, skipThisMax + nums[i]);
 			skipThisMax = max(skipThisMax, swap);
 		}
 		return max(robThisMax, skipThisMax);
 	}
};


