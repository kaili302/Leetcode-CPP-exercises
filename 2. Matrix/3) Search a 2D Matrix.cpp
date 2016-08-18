/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int HE = matrix.size();
        int WI = matrix[0].size();

        // search first column 
        int lo = 0, hi = HE - 1;
        int mid;
        while (lo < hi) {
        	mid = (lo + hi) / 2;
        	if (matrix[mid][0] == target) return true;
        	else if (matrix[mid][0] < target) {
        		if (lo == mid){
        			// only two lines left
        			if (matrix[hi][0] > target) hi--;
        			else lo++;
        		}else lo = mid;
        	}else if (matrix[mid][0] > target) hi = mid - 1;
        }
        if (hi < lo) return false;
        
       	// lo == hi, search on line 
        int line = lo;
        lo = 0, hi = WI - 1;
        while (lo <= hi){
        	mid = (lo + hi) / 2;
        	if (matrix[line][mid] == target) return true;
        	else if (matrix[line][mid] < target) lo = mid + 1;
        	else hi = mid - 1;
        }
        return false;
    }
};