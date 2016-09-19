/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely 
(ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

/*
1. invalid number (too small, too big, --, ++)
*/


class Solution {
private:
	bool isNum(char& c){
		return c <= '9' && c >= '0';
	}
public:
    int myAtoi(string str) {
		long num = 0;
		bool isNegative = false;
		if (str[0] == '+') ;
		else if (str[0] == '-') isNegative = true;
		else if (isNum(str[0])) num = stoi(str.substr(0, 1));
		else return 0;

		for (int i = 1; i < str.size(); i++){
			if (str[i] == ' ') continue;
			if (!isNum(str[i]))
				break;
			num = num * 10 + stoi(str.substr(i, 1));
			if (num > INT_MAX) return 0;
		}
		if (isNegative) num = -num;
		if (num < INT_MIN || num > INT_MAX)
			return 0;
		return num;
    }
};