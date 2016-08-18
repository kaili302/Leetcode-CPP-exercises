#ifndef STATUSCODE_HPP
#define STATUSCODE_HPP
/* status code returned after player's each move */

enum class StatusCode{
    WIN = 0,			// return when player wins
    TIE, 				// return when tie
    INVALID_STEP,		// return when play move an invalid step
    CONTINUE			// return when game is not finished
};

#endif