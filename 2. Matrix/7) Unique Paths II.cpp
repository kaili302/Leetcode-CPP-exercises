/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 
0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  		if (obstacleGrid.empty()) return 0;

  		int HE = obstacleGrid.size();
  		int WI = obstacleGrid[0].size();

  		vector<vector<int>> pathSum(HE, vector<int>(WI, 0));

  		for (int r = 0; r < HE; r++){
  			for (int c = 0; c < WI; c++){
  				if (obstacleGrid[r][c]) {
  					pathSum[r][c] == 0;
  					continue;
  				}
  				if (r == 0 && c == 0) pathSum[r][c] = 1;
  				else if (r == 0) pathSum[r][c] = pathSum[r][c-1];
  				else if (c == 0) pathSum[r][c] = pathSum[r-1][c];
  				else pathSum[r][c] = pathSum[r-1][c] + pathSum[r][c-1];
  			}
  		}
  		return pathSum[HE-1][WI-1];
    }
};