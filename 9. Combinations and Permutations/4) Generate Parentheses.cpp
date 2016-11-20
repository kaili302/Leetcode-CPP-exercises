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

class Solution{
private:
    void generateParenthesis(int left, int right, string& combination, vector<string>& result){
        if (!left && !right)
            result.push_back(combination);

        if (left > 0 && left <= right){
            combination.push_back('(');
            generateParenthesis(left - 1, right, combination, result);
            combination.pop_back();
        }
        if (right > 0){
            combination.push_back(')');
            generateParenthesis(left, right - 1, combination, result);
            combination.pop_back();   
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string combination;
        generateParenthesis(n, n, combination, result);
        return result;
    }
};