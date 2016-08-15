#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include <vector>
#include "StatusCode.hpp"

class TicTacToe{

private: 
	/* total steps */
    int m_totalSteps;
    
    /* board size: m_size * m_size */
    int m_size;

    /* game board */
    std::vector<std::vector<char>> m_board;

    /* player O */
    const char m_player_O;    

    /* player X */
    const char m_player_X;

    /* blank case on game board */
    const char m_blank;

    void initBoard();

    void printBoard();

    /* move to (row, col) position on game board */
    StatusCode move(const int &row, const int &col, const char &player);

public:
	/* constructor */
    TicTacToe (): m_player_O{'O'}, m_player_X{'X'}, m_blank{'_'}, m_totalSteps{0} { }

    /* start game */
    void start();
};

#endif 
