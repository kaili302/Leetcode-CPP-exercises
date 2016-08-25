/*
Given n pairs of parentheses, write a function to generate all 
combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

class Solution {
private:
	void generateParenthesis(int nLeft, int nRight, string &combination, vector<string> &result) {
		if (nLeft == 0 && nRight == 0){
			result.push_back(combination);
			return;
		}
		if (nLeft > nRight) return ;

		if (nLeft > 0){
			combination.push_back('(');
			generateParenthesis(nLeft - 1, nRight, combination, result);
			combination.pop_back();
		}
		combination.push_back(')');
		generateParenthesis(nLeft, nRight - 1, combination, result);
		combination.pop_back();       
    }
public:
    vector<string> generateParenthesis(int n) {
    	 string combination;
    	 combination.reserve(n*2);
    	 vector<string> result;
    	 generateParenthesis(n, n, combination, result);
    	 return result;
    }
};






