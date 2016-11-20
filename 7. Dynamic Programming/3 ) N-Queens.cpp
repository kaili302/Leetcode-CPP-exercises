/*
Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
 [".Q..",  // Solution 1
  "...Q",
  "Q...",
  "..Q."],

 ["..Q.",  // Solution 2
  "Q...",
  "...Q",
  ".Q.."]
]
*/


class Solution { 
public:
    bool isValid(vector<int>& comb){
        int row = comb.size() - 1, col = comb.back();
        for (int row1 = 0; row1 < comb.size() - 1; row1++)
            if (comb[row1] == col || abs(row - row1) == abs(col - comb[row1])) return false;
        return true;
    }

    void addResult(vector<int>& comb, vector<vector<string>>& res){
        vector<string> board(comb.size(), string(comb.size(), '.'));
        for (int i = 0; i < comb.size(); i++) board[i][comb[i]] = 'Q';
        res.push_back(board);
    }

    void solveNQueens(int row, int n, vector<int>& comb, vector<vector<string>>& res){
        if (row == n){
            addResult(comb, res);
            return;
        }
        for (int i = 0; i < n; i++){
            comb.push_back(i);
            if (isValid(comb)) solveNQueens(row + 1, n, comb, res);
            comb.pop_back();
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<int> comb;
        vector<vector<string>> res;
        solveNQueens(0, n, comb, res);
        return res;
    }
};
