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


class Solution {
private:
	void combine(int n, int start, int k, vector<int> &comb,vector<vector<int>> &combinations) {
		if (k == 0){
			combinations.push_back(comb);
			return;
		}
		for (int num = start; num <= n - k + 1; num++){
			comb.push_back(num);
			combine(n, start + 1, k - 1, comb, combinations);
			comb.pop_back();
		}
	}
public:
    vector<vector<int>> combine(int n, int k) {
       	vector<vector<int>> combinations;
       	vector<int> comb;
       	combine(n, 0, k, comb, combinations);
       	return combinations;
    }
};