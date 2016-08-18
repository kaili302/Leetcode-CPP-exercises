/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'. 
 A region is captured by flipping all 'O's into 'X's in that surrounded region. For example,
X X X X	ans. 	X X X X
X O O X			X X X X	
X X O X			X X X X
X O X X			X O X X
*/
class Solution {
private:
    const vector<pair<int, int>> dirs {{-1, 0},{0, -1},{0, 1},{1, 0}};
    // dfs -> segment fault (stack overflow I guess)
    void visitDFS(vector<vector<char>>& board, int r, int c, int HE, int WI){
        if (r < 0 || r >= HE || c < 0 || c >= WI || board[r][c] != 'O')
            return;
        board[r][c] = '#';
        for (auto &dir : dirs){
            visit(board, r + dir.first, c + dir.second, HE, WI);
        }
    }

    void visit(vector<vector<char>>& board, int r, int c, int HE, int WI){
        queue<pair<int, int>> q;
        q.push({r, c});
        board[r][c] = '#';
        while (q.size()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for (auto &dir : dirs){
                int x = r + dir.first, y = c + dir.second;
                if (x < 0 || x >= HE || y < 0 || y >= WI || board[x][y] != 'O') 
                    continue;
                board[x][y] = '#';
                q.push({x, y});
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) 
            return;

        int HE = board.size();
        int WI = board[0].size();

        // Traversal up side and down edge, mark unsurrounded region as '#'
        
        for (int c = 0; c < WI-1; c++) {
            if (board[0][c] == 'O') 
                visit(board, 0, c, HE, WI);
            if (board[HE-1][c] == 'O') 
                visit(board, HE-1, c, HE, WI);
        }

        // Traversal left and right edge, mark unsurrounded region as '#'
        for (int r = 0; r < HE; r++){
            if (board[r][0] == 'O') 
                visit(board, r, 0, HE, WI);
            if (board[r][WI-1] == 'O') 
                visit(board, r, WI-1, HE, WI);
        }

        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == '#') board[r][c] = 'O';
            }
        }
    }
};