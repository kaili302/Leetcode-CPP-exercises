/*
Given a collection of numbers that might contain duplicates,  return all possible unique permutations. 
eg. [1,1,2] have the following unique permutations: [1,1,2], [1,2,1], and [2,1,1].
*/

class Solution {
private:
	void permuteUnique(vector<int> nums, int i, vector<vector<int>>& result) {
		if (i == nums.size()){
			result.push_back(nums);
			return;
		}
		for (int k = i; k < nums.size(); k++){
			if (k != i && nums[k] == nums[i]) continue;
			swap(nums[i], nums[k]);
			permuteUnique(nums, i + 1, result);
		}
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
  		vector<vector<int>> result;
  		if (nums.empty()) return result;
  		sort(nums.begin(), nums.end());
		permuteUnique(nums, 0, result);
		return result;
    }
};
