/*
Given a set of distinct integers, nums, return all possible subsets.
Note: The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
  		vector<vector<int>> result{{}};
  		for (auto& num : nums){
  			int size = result.size();
  			for (int i = 0; i < size; i++){
				result[i].push_back(num);
				result.push_back(result[i]);
				result[i].pop_back();
  			}
  		}
  		return result;
    }
};