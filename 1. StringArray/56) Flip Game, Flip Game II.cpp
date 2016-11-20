/*
You are playing the following Flip Game with your friend: Given a string that 
contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". 
The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to compute all possible states of the string after one valid move.
*/

class Solution{
public:
	vector<string> move(string s){
		vector<string> result;
		for (int i = 0; i < s.size() - 1; i++){
			if (s[i] == '+' && s[i+1] == '+'){
				result.push_back(s);
				result.back()[i] = '-';
				result.back()[i+1] = '-';
			}
		}
		return result;
	}
};


/*
You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, 
you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.

Write a function to determine if the starting player can guarantee a win.

For example, given s = "++++", return true. The starting player can guarantee a win by flipping the middle "++" to become "+--+".
*/
class Solution{
public:
    bool canWin(string s){
        if (s.size() <= 1) return false;
        for (int i = -1; (i = s.find("++", i + 1)), i != -1; )
            if (!canWin(s.substr(0, i) + "--" + s.substr(i + 2))) 
                return true;
        return false;   
    }
};

// back tracking, n^n




