/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Above is a 3 x 7 grid. How many possible unique paths are there?
*/



class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m * n == 0) return 0;
		vector<vector<int>> pathSum(m, vector<int>(n, 0));

		for (int r = 0; r < m; r++){
			for (int c = 0; c < n; c++) {
				if (r == 0 || c == 0) pathSum[r][c] = 1;
				else pathSum[r][c] = pathSum[r-1][c] + pathSum[r][c-1];						
			}
		}
		return pathSum[m-1][n-1];
    }
};