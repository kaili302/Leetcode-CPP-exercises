/**
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
  		int sum = nums[0]+nums[1]+nums[2];
  		int minDiff = abs(target-sum);
  		sort(nums.begin(), nums.end());
  		for (int i=0; i<nums.size(); i++) {
  			if (i>0 && nums[i]==nums[i-1]) continue;
  			int lo = i+1;
  			int hi = nums.size()-1;
  			while (lo<hi) {
  				int currSum=nums[i]+nums[lo]+nums[hi];
  				if (abs(target-currSum) < minDiff) {
					minDiff= abs(target-currSum);
					sum = currSum;			
				}
  				if (currSum == target) return currSum;
  				else if (currSum < target) lo++;
  				else if (currSum > target) hi--;
  			}
  		}
  		return sum;
    }
};