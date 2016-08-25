/*
Sudoku Solver: You may assume that there will be only one unique solution.
*/
#include <vector>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/


// 会time limit 有时
class Solution {
private:
	const int N = 9;
	bool isValidStep(vector<vector<char>>& board, int row, int col){
		vector<bool> isTakenRow(N, false);
		vector<bool> isTakenCol(N, false);
		for (int i = 0; i < N; i++){
			if (board[row][i] != '.'){
				if (isTakenRow[board[row][i]-'1']) return false;
				isTakenRow[board[row][i]-'1'] = true;
			}

			if (board[i][col] != '.'){
				if (isTakenCol[board[i][col]-'1']) return false;
				isTakenCol[board[i][col]-'1'] = true;
			}
		}
		vector<bool> isTaken(N, false);
		for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++){
			for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3;j++){
				if (board[i][j] != '.'){
					if (isTaken[board[i][j]-'1']) return false;
					isTaken[board[i][j]-'1'] = true;
				}
			}
		}
		return true;
	}

public:
    void solveSudoku(vector<vector<char>>& board) {
    	solve(board);
    }
    bool solve(vector<vector<char>>& board) {
    	for (int r = 0; r < N; r++){
    		for (int c = 0; c < N; c++){
    			if (board[r][c] != '.') continue;

    			// replace '.' by 1 to 9 to check if is valid
    			for (char val = '1'; val <= '9'; val++){
    				board[r][c] = val;
    				if (isValidStep(board, r, c))
    					if (solve(board)) return true;
    			}
    			board[r][c] = '.';
    			return false;
    		}
    	}
    	return true;
    }
};


// optimized version

class Solution {
private:
	const int N = 9;
	bool isValidStep(vector<vector<char>>& board, int row, int col){
		bool isTakenRow[0] = {false};
		bool isTakenCol[0] = {false};

		for (int i = 0; i < N; i++){
			if (board[row][i] != '.'){
				if (isTakenRow[board[row][i]-'1']) return false;
				isTakenRow[board[row][i]-'1'] = true;
			}

			if (board[i][col] != '.'){
				if (isTakenCol[board[i][col]-'1']) return false;
				isTakenCol[board[i][col]-'1'] = true;
			}
		}
		bool isTaken[0] = {false};
		for (int i = (row / 3) * 3; i < (row / 3) * 3 + 3; i++){
			for (int j = (col / 3) * 3; j < (col / 3) * 3 + 3;j++){
				if (board[i][j] != '.'){
					if (isTaken[board[i][j]-'1']) return false;
					isTaken[board[i][j]-'1'] = true;
				}
			}
		}
		return true;
	}

public:
    void solveSudoku(vector<vector<char>>& board) {
    	deque<pair<int, int>> points;
    	for (int r = 0; r < N; r++){
    	    for (int c = 0; c < N; c++){
    	    	if (board[r][c] == '.')
    	    		points.emplace_back(r, c);
    	    }
    	}
    	solve(board, points, 0);
    }
    bool solve(vector<vector<char>>& board, deque<pair<int, int>> &points, int idx) {
		// replace '.' by 1 to 9 to check if is valid
		if (idx >= points.size()) return true;
		
		int row = points[idx].first, col = points[idx].second;
		for (char val = '1'; val <= '9'; val++){
			board[row][col] = val;
			if (!isValidStep(board, row, col)) continue;
			if (solve(board, points, idx + 1)) return true;
			board[row][col] = '.';
		}
		return false;
    }
};




