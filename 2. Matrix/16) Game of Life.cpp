/*
Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules:
Any live cell with fewer than two live neighbors dies, as if caused by under-population. Any live cell with two or three live neighbors lives on to the next generation. Any live cell with more than three live neighbors dies, as if by over-population.. Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if (board.empty()) return ;
        const int live_to_die = 3;
        const int die_to_live = 4;

        // to each neighbors
        vector<pair<int, int>> dirs {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, 1}, {1, 0}, {1, 1}};

        int HE = board.size();
        int WI = board[0].size();
        for (int r = 0; r < HE; r++) {
            for (int c = 0; c < WI; c++) {
                /* count live neighbors */
                int count = 0;
                for (auto &dir : dirs) {
                    int x = r + dir.first, y = c + dir.second;
                    if (x < 0 || x >= HE || y < 0 || y >= WI)
                        continue;
                    if (board[x][y] % 2) count++;
                } 

                if (count < 2 && board[r][c] % 2) board[r][c] = live_to_die;
                if (count == 3 && (board[r][c] % 2 == 0)) board[r][c] = die_to_live;
                if (count > 3 && board[r][c] % 2) board[r][c] = live_to_die;
            }
        }

        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++) {
                if (board[c][r] == live_to_die) board[c][r] = 0;
                if (board[c][r] == die_to_live) board[c][r] = 1;
            }
        }   
    }
};