/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
	vector<string> summaryRanges(vector<int>& nums) {
  		if (nums.empty()) return {};
  		vector<string> result;

  		int left = 0;
  		for (int i = 0; i < nums.size() - 1; i++){
  			if (nums[i+1] == nums[i] + 1) continue;
  			else {
  				if (left == i) result.push_back(to_string(nums[i]));
  				else result.push_back(to_string(nums[left]) + "->" + to_string(nums[i]));
  				left = i + 1;
  			}
  		}
  		if (left == nums.size() - 1) result.push_back(to_string(nums.back()));
  		else result.push_back(to_string(nums[left]) + "->" + to_string(nums.back()));
  		return result;
    }
};