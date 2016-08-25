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

class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
    	if (nums.empty()) return {};
		
		queue<vector<int>> q;
		q.push({});
		for (auto &num : nums){
			int size = q.size();
			for (int i = 0; i < size; i++){
				vector<int> &oldList = q.front();
				for (int j = 0; j <= oldList.size(); i++){
					vector<int> newList(oldList);
					newList.insert(newList.begin() + j, num);
					q.push(newList);
				}
				q.pop();
			}
		}
		return {q.begin(), q.end()};
    }
};


// recursion way. 
class Solution {
private:
	void permute(vector<int> &nums, int i, vector<vector<int>> &result){
		if (i == nums.size() - 1){
			result.push_back(nums);
			return;
		}
		for (int k = i; k < nums.size(); k++){
			swap(nums[i], nums[k]);
			permute(nums, k + 1, result);
			swap(nums[k], nums[i]);
		}
	}
public:
    vector<vector<int>> permute(vector<int> &nums) {
    	if (nums.empty()) return {};
		vector<vector<int>> result;
		permute(nums, 0, result);
    }
};

