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
  void combinationSum3(int idx, int k, int target, vector<int>& v, vector<vector<int>>& result){
    if (!k){
      if (!target)
        result.push_back(v);
      return;
    }
    for (int i = idx; i <= 9 && i <= target; i++){
      v.push_back(i);
      combinationSum3(i + 1, k - 1, target - i, v, result);
      v.pop_back();
    }
  }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
      vector<vector<int>> result;
      vector<int> v;
      combinationSum3(1, k, n, v, result);
      return result;
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
      sort(nums.begin(), nums.end());
      for (int i = 1; i <= target; i++){
        for (auto& num : nums){
          if (num > i) break;
          dp[i] += dp[i-num];
        }
      }
      return dp[target];
    }
};