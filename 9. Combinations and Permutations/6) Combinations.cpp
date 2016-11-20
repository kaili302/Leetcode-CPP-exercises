/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution{
private:
  void combine(int num, int N, int k, vector<int>& v, vector<vector<int>>& result){
    if (k == 0){
      result.push_back(v);
      return;
    }
    for (int i = num; i <= N + 1 - k; i++){
      v.push_back(i);
      combine(i + 1, N, k - 1, v, result);
      v.pop_back();
    }
  }
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> result;
      vector<int> v;
      combine(1, n, k, v, result);
      return result;
    }  
};