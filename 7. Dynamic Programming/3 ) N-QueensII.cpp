/*
Now, instead outputting board configurations, return the total number of distinct solutions.
*/
class Solution {
public:
    bool isValid(vector<int>& comb){
        int row = comb.size() - 1, col = comb.back();
        for (int row1 = 0; row1 < comb.size() - 1; row1++)
            if (comb[row1] == col || abs(row - row1) == abs(col - comb[row1])) return false;
        return true;
    }

    void solveNQueens(int row, int n, vector<int>& comb, int& res){
        if (row == n){
            res++;
            return;
        }
        for (int i = 0; i < n; i++){
            comb.push_back(i);
            if (isValid(comb)) solveNQueens(row + 1, n, comb, res);
            comb.pop_back();
        }
    }

    int totalNQueens(int n) {
        vector<int> comb;
        int count = 0;
        solveNQueens(0, n, comb, count);
        return count;
    }
};