/** 
Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are +, -, *, /. Each operand may be an integer or another expression. For example:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
    	if (tokens.size() == 1) return str2int(tokens.back());
        stack<int> stack{};
        for (string &token : tokens) {
        	if (isOperator(token)) {
        		int y = stack.top();
        		stack.pop();
        		int x = stack.top();
        		stack.pop();
        		stack.push(calculate(x, y, token));
        	}else 
        		stack.push(str2int(token));
        }
        return stack.top();
    }

    bool isOperator (string &token) {
    	return token == "+" ||token == "-" ||token == "*" ||token == "/";
    }

    int calculate (int x, int y, string &op) {
    	// x is the first operand
    	if (op == "*") return x*y;
    	else if (op == "/") return x/y;
    	else if (op == "+") return x+y;
    	else return x-y;
	}

	int str2int (string &num) {
		int tmp;
		istringstream iss(num);
		iss >> tmp;
		return tmp;
	}
};

