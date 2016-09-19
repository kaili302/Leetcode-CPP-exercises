/** 
Evaluate the value of an arithmetic expression in Reverse Polish Notation. Valid operators are +, -, *, /. Each operand may be an integer or another expression. For example:

  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
*/

class Slution{
private:
    bool isNum(string& token){
        return token != "*" && token != "-" && token != "+" && token != "/";
    }

    int calculate(int& x, int& y, string& op){
        if (op == "*") return x * y;
        else if (op == "/") return x / y;
        else if (op == "+") return x + y;
        else return x - y;
    }

public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        for (auto& token : tokens){
            if (isNum(token)) s.push(stoi(token));
            else {
                int y = s.top(); s.pop();
                int x = s.top(); s.pop();
                s.push(calculate(x, y, token));
            }
        }
        return s.top();
    }
};
