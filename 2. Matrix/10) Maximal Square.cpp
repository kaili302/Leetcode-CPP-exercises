/*
Given a 2D binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.

*/


// a typical DP problem

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int HE = matrix.size();
		int WI = matrix[0].size();
		int maxEdge = 0;
		vector<vector<int>> dp(HE, vector<int>(WI, 0));

		for (int r = 0; r < HE; r++){
			for (int c = 0; c < WI; c++){
				if (matrix[r][c] == '1'){
					dp[r][c] = 1;
					if (r != 0 && c != 0) 
						dp[r][c] += min(min(dp[r-1][c], dp[r][c-1]), dp[r-1][c-1]);
				}else dp[r][c] = 0;
				maxEdge = max(maxEdge, dp[r][c]);
			}
		}

		return maxEdge*maxEdge;
    }
};