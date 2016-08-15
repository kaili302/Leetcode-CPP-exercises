/*
Design a Tic-tac-toe game that is played between two players on a n x n grid.
*/
#include <iostream>
#include <iomanip>

enum class StatusCode{
    PLAYER_WIN = 0,
    WRONG_STEP,
    CONTINUE, 
    TIE
};

class TicTacToe{
private: 
    int m_totalSteps;
    int m_size;
    std::vector<std::vector<char>> m_board;

    void initBoard() {
        for (int i=0; i<m_size; i++) {
            m_board[i].assign(m_size, m_BLANK);
        }
    }

    void printBoard() {
        std::cout << std::fix;
        for (auto &row:m_board) {
            for (auto &val : row) {
                std::cout << setw(3) << internal << val;
            }
            std::cout <<std::endl;
        }
    }


public:
    const char m_PLAYER_X;
    const char m_PLAYER_O;    
    const char m_BLANK;

    Solution (int size): m_PLAYER_O{'O'}, m_PLAYER_X{'X'}, m_BLANK{'_'}, m_totalSteps{0} { }

    StatusCode move(const int &row, const int &col, const char &player){
        if (row >= m_size || col >= m_size || board[row][col] != ' ') 
            return StatusCode::WRONG_STEP;

        board[row][col] = player;

        // check row
        int count = 0;
        for (int j = 0; j<m_size; j++) {
            if (m_board[row][j] != player) break;
            count++;
        }
        if (count == m_size) return StatusCode::PLAYER_WIN;

        // check column 
        count = 0;
        for (int i=0; i<m_size; i++) {
            if (m_board[i][col] != player) break;
            count++;
        }
        if (count == m_size) return StatusCode::PLAYER_WIN;

        // check \
        count = 0;
        if (int i=0; i<m_size; i++) {
            if (m_board[i][i] != player) break;
            count++;
        }
        if (count == m_size) return StatusCode::PLAYER_WIN;

        // check /
        count = 0;
        if (int i=0; i<m_size; i++) {
            if (m_board[i][m_size-1-i] != player) break;
            count++;
        }
        if (count == m_size) return StatusCode::PLAYER_WIN;

        m_totalSteps++;
        if (m_totalSteps == m_size*m_size) return StatusCode::TIE;

        return StatusCode::CONTINUE;
    }

    void start() {
        std::cout << "cutomize the board size n*n, n=: ";
        std::cin >> m_size;
        initBoard();

        StatusCode status = StatusCode::CONTINUE;
        int stepCount = 0;
        std::cout << "game start, input 4 5 if you want to move to (4, 5)\n";
        int row = 0;
        int col = 0;
        ostringstream oss{""};
        const char &player;

        while (status == StatusCode::CONTINUE) {
            printBoard();
            player = m_PLAYER_O;
            if (stepCount%2) player = m_PLAYER_X;

            std::cout << "player " << player << " move to: ";
            getline(oss, cin);
            oss >> row;
            oss >> col;
            oss.str("");
            move(row, col, player);
        }
    }
}