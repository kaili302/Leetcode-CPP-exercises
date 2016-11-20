/*
Given numRows, generate the first numRows of Pascal's triangle. 
For example, given numRows = 5, the result should be:

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution{
public:
	vector<vector<int>> generate(int n){
		if (n <= 0) return {};

		vector<vector<int>> triangle;
		for (int level = 1; level <= n; level++){
			vector<int> nums;
			for (int i = 0; i < level; i++){
				if (i ==0 || i == level - 1) nums.push_back(1);
				else nums.push_back(triangle.back()[i] + triangle.back()[i-1]);
			}
			triangle.push_back(nums);
		}
		return triangle;
	} 
};


/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].
*/

class Solution{
public:
	vector<int> getRow(int n){
		n++;
		if (n <= 0) return {};

		vector<int> prevLevel(n), currLevel(n);
		vector<int>& prev = prevLevel;
		vector<int>& curr = currLevel;

		for (int level = 1; level <= n; level++){
			for (int i = 0; i < level; i++){
				if (i == 0 || i == level - 1) curr[i] = 1;
				else curr[i] = prev[i] + prev[i-1];
			}
			prev = curr;
		}
		return currLevel;
	} 
};
