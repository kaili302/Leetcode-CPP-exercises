/*
Given a collection of distinct numbers, return all possible permutations.
For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
// recursion way. 
class Solution{
private:
	void permute(int idx, vector<int>& nums, vector<vector<int>>& result){
		if (idx == nums.size()){
			result.push_back(nums);
			return;
		}
		for (int i = idx; i < nums.size(); i++){
			swap(nums[i], nums[idx]);
			permute(idx + 1, nums, result);
			swap(nums[i], nums[idx]);
		}
	}
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> result;
		permute(0, nums, result);
        return result;
	}
};