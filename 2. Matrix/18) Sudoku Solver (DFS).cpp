/*
Sudoku Solver: You may assume that there will be only one unique solution.
*/
#include <vector>
using namespace std;

class Solution{
private:
	const int SIZE = 9;
public:
	void solve(vector<vector<char>> &board){



	}

	bool isValid(vector<vector<char>> &board){
		if (board.size() != SIZE || board[0].size() != SIZE)
			return false;

		// check rows and cols
		for (int i =0; i < SIZE; i++){
			vector<bool> rowCheck(9, false), colCheck(9, false);
			for (int j = 0; j < SIZE; j++){
				// check row
				if (board[i][j] != '.'){
					if (rowCheck[board[i][j]-'1']) return false;
					rowCheck[board[i][j]-'1'] = true;
				}
				// check col
				if (board[j][i] != '.'){
					if (colCheck[board[j][i]-'1']) return false;
					colCheck[board[j][i]-'1'] = true;
				}
			}
		}

		// check all 9cells
		for (int i = 0; i <= 6; i += 3){
			for (int j = 0; j <= 6; j += 3){
				// check eack 9cells
				vector<bool> checkCell(9, false);
				for (int r = i; r < i + 3 ; r++){
					for (int c = j; c < j + 3; c++){
						if (board[r][c] != '.'){
							if (checkCell[board[r][c]-'1']) return false;
							checkCell[board[r][c]-'1'] = true;
						}
					}
				}
			}
		}
		return true;
	}
};

