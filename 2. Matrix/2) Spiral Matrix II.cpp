/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/



class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        if (n == 0) return matrix;

        int le = 0, ri = n-1;
        int up = 0, dw = n-1;
        int counter = 1;
        while(le < ri) {
        	
        	// up
        	int tmp = le;
        	while (tmp < ri) matrix[up][tmp++] = counter++;

        	// right
        	tmp = up;
        	while (tmp < dw) matrix[tmp++][ri] = counter++;

        	// down
        	tmp = ri;
        	while (tmp > le) matrix[dw][tmp--] = counter++;

        	// left
        	tmp = dw;
        	while (tmp > up) matrix[tmp--][le] = counter++;

        	le++; ri--;
        	up++; dw--;
        }
        if (le == ri) matrix[up][le] = counter;
        return matrix;
    }
};