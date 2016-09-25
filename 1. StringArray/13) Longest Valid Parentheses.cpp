/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

Subscribe to see which companies asked this question
*/

class Solution {
private:
bool isValid(int lo, int hi, string& s, vector<vector<bool>>& dp){
	return (s[lo] == '(' && s[hi] == ')') && (lo + 1 == hi || dp[lo+1][hi-1]);
}
public:
    int longestValidParentheses(string s) {
    	int size = s.size();
    	if (size <= 1) return 0;
  		vector<vector<bool>> dp(size, vector<bool>(size, false));
  		int maxLen = 0;
  		for (int i = size - 2; i >= 0; i--){
  			for (int j = i + 1; j < size; j++){
  				if (isValid(i, j, s, dp)) 
  					dp[i][j] == true;
  				else {
  					for (int k = i + 1; k + 1 < j; k++){
  						if (dp[i][k] && dp[k+1][j]) {
  							dp[i][j] = true;
  							break;
  						}
  					}
  				}
  				if (dp[i][j]) 
  					maxLen = max(maxLen, j - i + 1);
  			}
  		}
  		return maxLen;
    }
};