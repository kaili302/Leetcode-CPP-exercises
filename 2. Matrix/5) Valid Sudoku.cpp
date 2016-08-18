/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    	if (board.empty() || board.size() != board[0].size()) 
    		return false;

    	const int N =9;
  		
    	array<int, 9> dict;
    	array<int, 9> dict2;
  		
    	for (int i = 0; i < N; i++) {
    		
    		dict.fill(0);
    		dict2.fill(0);
    		for (int j = 0; j < N; j++){
    			// check row
    			if (board[i][j] != '.') {
	    			if (dict[board[i][j]-'1']) return false;
	    			dict[board[i][j]-'1'] = 1;
    			}
				// check column 
    			if (board[j][i] != '.') {
	    			if (dict2[board[j][i]-'1']) return false;
	    			dict2[board[j][i]-'1'] = 1;
    			}
    		}
    	}

    	// check 9* 9-cell
    	for (int i = 0; i <= 6; i += 3){
    		for (int j = 0; j <= 6; j+=3) {
				//check 9-cell
				dict.fill(0);
				for (int r = i; r < i+3; r++){
					for (int c = j; c < j+3; c++){
						if (board[r][c] == '.') continue;
			    		if (dict[board[r][c]-'1']) return false;
			    		dict[board[r][c]-'1'] = 1;
					}
				}
    		}
    	}
    	return true;
    }
};