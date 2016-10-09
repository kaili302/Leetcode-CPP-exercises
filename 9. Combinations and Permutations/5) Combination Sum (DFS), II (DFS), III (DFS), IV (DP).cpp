/*
Given a set of candidate numbers (C) and a target number (T), 
find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
For example, given candidate set [2, 3, 6, 7] and target 7, 
A solution set is: 
[
  [7],
  [2, 2, 3]
]
*/
// there are repetitions in C
class VectorHash{
public:
  size_t operator()(const vector<int>& nums) const {
    size_t hashval= 0;
    for (int i = 0; i < nums.size(); i++){
      if (i % 2) hashval ^= (nums[i] >> 1);
      else hashval ^= (nums[i] << 1);
    }
    return hashval;
  }
};

class VectorEqual{
public:
  bool operator()(const vector<int>& nums1, const vector<int>& nums2) const{
    if (nums1.size() != nums2.size()) return false;
    for (int i = 0; i < nums1.size(); i++){
      if(nums1[i] != nums2[i]) return false;
    }
    return true;
  }
};

typedef unordered_set<vector<int>, VectorHash, VectorEqual> hashset_t;
class Solution {
private:
    void combinationSum(vector<int>& candidates, int idx, int target, vector<int>& combination, hashset_t& result){
        if (target == 0){
            result.insert(combination);
            return;
        }

        for (int i = idx; i < candidates.size() && candidates[i] <= target; i++){
            combination.push_back(candidates[i]);
            combinationSum(candidates, i, target - candidates[i], combination, result);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {{}};
        hashset_t result;
        vector<int> combination; 
        sort(candidates.begin(), candidates.end());
        combinationSum(candidates, 0, target, combination, result);
          return {result.begin(), result.end()};
    }
};



// or 

class Solution {
private:
  void combinationSum(vector<int>& candidates, int idx, int target, vector<vector<int>>& result, vector<int>& combination) {
    if (!target){
      result.push_back(combination);
      return;
    }
    for (int i = idx; i < candidates.size() && candidates[i] <= target; i++){
      if (i > idx && candidates[i] == candidates[i-1]) continue; // here avoid duplication
      combination.push_back(candidates[i]);
      combinationSum(candidates, i, target - candidates[i], result, combination);
      combination.pop_back();
    }
  }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum(candidates, 0, target, result, combination);
      return result;
    }
};

/*
5.2 Combination Sum II (DFS)
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
Each number in C may only be used once in the combination.
*/

class Solution {
private:
  void combinationSum2(vector<int>& candidates, int idx, int target, vector<vector<int>>& result, vector<int>& combination) {
    if (!target){
      result.push_back(combination);
      return;
    }
    for (int i = idx; i < candidates.size() && candidates[i] <= target; i++){
      if (i > idx && candidates[i] == candidates[i-1]) continue; // here avoid duplication
      combination.push_back(candidates[i]);
      combinationSum2(candidates, i + 1, target - candidates[i], result, combination);
      combination.pop_back();
    }
  }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      vector<vector<int>> result;
      vector<int> combination;
      sort(candidates.begin(), candidates.end());
      combinationSum2(candidates, 0, target, result, combination);
      return result;
    }
};


/*
5.3 Combination Sum III (DFS)
Find all possible combinations of k numbers that add up to a number n, given that only 
numbers from 1 to 9 can be used and each combination should be a unique set of numbers. 
Ensure that numbers within the set are sorted in ascending order.
Example 1: Input: k = 3, n = 7 Output: [[1,2,4]]
Example 2: Input: k = 3, n = 9 Output: [[1,2,6], [1,3,5], [2,3,4]]
*/

class Solution {
private:
  void combinationSum3(int k, int start, int target, vector<int>& combination ,vector<vector<int>>& combinations) {
		if (k == 0){
			if (target == 0) combinations.push_back(combination);
			return;
		}
		for (int i = start; i <= 9 && i <= target; i++){
			combination.push_back(i);
			combinationSum3(k - 1, i + 1, target - i, combination, combinations);
			combination.pop_back();
		}
	}
public:
    vector<vector<int>> combinationSum3(int k, int n) {
  		// 1 + 2 +..+ 9 == 45
  		if (n > 45) return {};
  		vector<int> combination;
  		vector<vector<int>> combinations;
  		combinationSum3(k, 1, n, combination, combinations);
  		return combinations;
    }
};


/*
Given an integer array with all positive numbers and no duplicates, 
find the number of possible combinations that add up to a positive integer target.

nums = [1, 2, 3]
target = 4

The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)

Note that different sequences are counted as different combinations.

Therefore the output is 7.
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target + 1, 0);
    	dp[0] = 1;
  		for (int i = 0; i <= target; i++){
  			for(auto& num : nums){
  				if (i - num < 0) break;  															
  				dp[i] += dp[i-num];
  			}
  		}
  		return dp[target];
    }
};










