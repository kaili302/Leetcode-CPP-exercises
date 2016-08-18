/*
Given a matrix of m x n elements (m rows, n columns), 
return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty()) return result;

        int HE = matrix.size();
        int WI = matrix[0].size();

        int le = 0, ri = WI-1, up = 0, dw = HE-1; 
        int tmp; // save value temporarily
       	while(le < ri && up < dw) {
       		// up
       		tmp = le;
       		while (le < ri) result.push_back(matrix[up][le++]);
       		le = tmp;

       		// right
       		tmp = up;
       		while(up < dw) result.push_back(matrix[up++][ri]);
       		up = tmp;

       		// down
       		tmp = ri;
       		while(ri > le) result.push_back(matrix[dw][ri--]);
       		ri = tmp;

       		//left
       		tmp = dw;
       		while (dw > up) result.push_back(matrix[dw--][le]);
       		dw = tmp;
       		up++; dw--; 
       		le++; ri--;
       	}
        if (le > ri || up > dw)
           	return result;
        while(le < ri) result.push_back(matrix[up][le++]);
       	while(up < dw) result.push_back(matrix[up++][le]);
       	result.push_back(matrix[up][le]);
       	    return result;
    }
};