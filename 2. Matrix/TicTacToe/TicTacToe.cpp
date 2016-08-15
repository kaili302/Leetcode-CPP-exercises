#include <iostream>
#include <iomanip>
#include <vector>

#include "StatusCode.hpp"
#include "TicTacToe.hpp"


void TicTacToe::initBoard(){
    for (int i=0; i<m_size; i++) {
    	m_board.push_back(std::vector<char>());
        m_board[i].assign(m_size, m_blank);
    }
}


void TicTacToe::printBoard() {
    std::cout << std::fixed;
    for (auto &row:m_board) {
        for (auto &val : row) {
            std::cout << std::setw(3) << std::internal << val;
        }
        std::cout <<std::endl;
    }
}

StatusCode TicTacToe::move(const int &row, const int &col, const char &player){
	// move out of board, or move to occupied position
    if (row >= m_size || col >= m_size || m_board[row][col] != m_blank) 
        return StatusCode::INVALID_STEP;

    m_board[row][col] = player;

    // check row
    int count = 0;
    for (int i = 0; i<m_size; i++) {
        if (m_board[row][i] != player) break;
        count++;
    }
    if (count == m_size) return StatusCode::WIN;

    // check column 
    count = 0;
    for (int i=0; i<m_size; i++) {
        if (m_board[i][col] != player) break;
        count++;
    }
    if (count == m_size) return StatusCode::WIN;

    // check \
    count = 0;
    for (int i=0; i<m_size; i++) {
        if (m_board[i][i] != player) break;
        count++;
    }
    if (count == m_size) return StatusCode::WIN;

    // check /
    count = 0;
    for (int i=0; i<m_size; i++) {
        if (m_board[i][m_size-1-i] != player) break;
        count++;
    }
    if (count == m_size) return StatusCode::WIN;
    
    m_totalSteps++;
    if (m_totalSteps == m_size*m_size) return StatusCode::TIE;

    return StatusCode::CONTINUE;
}

void TicTacToe::start() {
    std::cout << "set game board size n*n, n=: ";
    std::cin >> m_size;
    initBoard();
    
    int row = 0;
    int col = 0;
    char player = ' ';
    StatusCode status = StatusCode::CONTINUE;
    int stepCount = 0;
	std::cout << "Player O starts first.\n";

    while (status != StatusCode::WIN && status != StatusCode::TIE) {
        printBoard();
        if (stepCount%2) player = m_player_X;
        else player = m_player_O;

        std::cout << "Player " << player << " move to (e.g 0 1): ";
        std::cin >> row;
        std::cin >> col;
        std::cin.ignore(10, '\n');

        status = move(row, col, player);
        if (status == StatusCode::INVALID_STEP) 
        	std::cout << "Invalid step ("<< row << "," << col << "). move again" <<std::endl;
        else
        	stepCount++;
    }
    // end of game
    printBoard();
    if (status == StatusCode::WIN) {
    	std::cout << "Player " << player << " win!" <<std::endl;
    }else std::cout << "Tie" <<std::endl;
}

