/*Given a m x n grid filled with non-negative numbers, find a path from 
top left to bottom right which minimizes the sum of all numbers along its path. */

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int HE = grid.size();
        int WI = grid[0].size();

        vector<vector<int>> pathSum(HE, vector<int>(WI, 0));
        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                if (r == 0 && c == 0) pathSum[r][c] = 0;
                else if (r == 0) pathSum[r][c] = pathSum[r][c-1];
                else if (c == 0) pathSum[r][c] = pathSum[r-1][c];       
                else pathSum[r][c] = min(pathSum[r][c-1], pathSum[r-1][c]);
                pathSum[r][c] += grid[r][c];
            }
        }
        return pathSum[HE-1][WI-1];
    }
};