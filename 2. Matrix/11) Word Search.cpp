/*
Given a 2D board and a word, find if the word exists in the grid.
The word can be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once.
For example, given board =
[
  ["ABCE"],
  ["SFCS"],
  ["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/


class Solution {
private:
	const vector<pair<int, int>> dirs{{-1, 0},{1, 0},{0, -1},{0, 1}};

	bool exist(vector<vector<char>> &board, int x, int y, int HE, int WI, string &word, int idx){
		if (x < 0 || x >= HE || y < 0 || y>=WI || board[x][y] != word[idx]) 
			return false;
		
		if (idx == word.length() - 1)	
			return true;
		
		char tmp = board[x][y];
		board[x][y] = '#';

		for (auto &dir : dirs){
			if (exist(board, x + dir.first, y + dir.second, HE, WI, word, idx + 1))
				return true;
		}
		board[x][y] = tmp;
		return false;
	}

public:
    bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || word.empty()) 
			return false;

		int HE = board.size();
		int WI = board[0].size();

		for (int r = 0; r < HE; r++){
			for (int c = 0; c < WI; c++){
				if (exist(board, r, c, HE, WI, word, 0))
					retrn true;
			}
		}
		return false;
    }
};