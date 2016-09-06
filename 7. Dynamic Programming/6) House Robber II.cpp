/*
After robbing those houses on that street, the thief has found himself a new place for his thievery 
so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is 
the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of
 money you can rob tonight without alerting the police.
*/

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.empty()) return 0;
    	int maxRobThis = 0;
 		int maxSkipThis = 0;
 		int maxRob = nums[0];
 		// skip the first house
 		for (int i = 1; i < nums.size(); i++){
 			int tmp = maxSkipThis;
 			maxSkipThis = max(maxSkipThis, maxRobThis);
 			maxRobThis = tmp + nums[i];
 		}
 		maxRob = max(maxRob, max(maxRobThis, maxSkipThis));
 		// skip the last house
 		maxRobThis = 0;
 		maxSkipThis = 0;
 		for (int i = 0; i < nums.size() - 1; i++){
 			int tmp = maxSkipThis;
 			maxSkipThis = max(maxSkipThis, maxRobThis);
 			maxRobThis = tmp + nums[i];
 		}
 		maxRob = max(maxRob, max(maxRobThis, maxSkipThis));
 		return maxRob;       
    }
};