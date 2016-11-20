class Solution {
private:
	bool isDigit(char& c){
		return c <= '9' && c >= '0';
	}
public:
	int calculate(string s) {
		stack<char> opSecond;
		stack<string> nums;
		int i = -1;
		do{
			i++;
			if (s[i] == ' ') continue;
			else if (s[i] == '(') nums.push("(");
			else if (s[i] == ')') {
				int num = stoi(nums.top());
				nums.pop(); nums.pop();
				if (opSecond.size()){
					int num2 = stoi(nums.top());
					nums.pop();
					nums.push(to_string(opSecond.top() == '+' ? num + num2 : num2 - num));
					opSecond.pop();
				}else nums.push(to_string(num));
			}else if ((s[i] == '+' || s[i] == '-') && (nums.size() && nums.top() != "(") ) opSecond.push(s[i]);
			else{
				//we get a number
				int tmp = i;
				while (++i < s.size() && isDigit(s[i]));
				if (nums.size() && nums.top() != "("){
					int num = stoi(s.substr(tmp, i - tmp));
					int num2 = stoi(nums.top());
					nums.pop();
					nums.push(to_string(opSecond.top() == '+' ? num + num2 : num2 - num));
					opSecond.pop();
				}else nums.push(s.substr(tmp, i - tmp));
				i--;
			}
		}while (i < s.size() - 1);
		return stoi(nums.top());
	}
};

/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . 
The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/
class Solution {
private:
    int getNum(const string& s, int& idx){
        int start = idx;
        while (++idx < s.size() && (s[idx] <= '9' && s[idx] >= '0'));
        idx--;
        return stoi(s.substr(start, idx - start + 1));
    }

    long calculate(long num1, char op, long num2){
        if (op == '*') return num1 * num2;
        else if (op == '/') return num1 / num2;
        else if (op == '+') return num1 + num2;
        else return num1 - num2;
    }

public:
    int calculate(string s) {
        char opFirst = 0, opSecond = 0;
        long numFirst, numSecond;
        int i = -1;
        while (++i < s.size()){
            if (s[i] == ' ') continue;
            else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if (opFirst) opSecond = s[i];
                else opFirst = s[i];
            }else{
                // find a number here
                if (opFirst && opSecond) {
                	if ((opSecond == '*' || opSecond == '/') && opFirst != '/')
                        numSecond = calculate(numSecond, opSecond, getNum(s, i));
                    else{
                        numFirst = calculate(numFirst, opFirst, numSecond);
                        opFirst = opSecond;
                        numSecond = getNum(s, i);
                    }
                    opSecond = 0;
                }else if (opFirst) numSecond = getNum(s, i);
                else numFirst = getNum(s, i);
            }
       }
       return opFirst ? calculate(numFirst, opFirst, numSecond) : numFirst;
    }
};