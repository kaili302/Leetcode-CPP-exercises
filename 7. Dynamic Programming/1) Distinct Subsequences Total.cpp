/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters.
(ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/


class Solution {
public:
    int numDistinct(string s, string t) {
		int s_size = s.length();
		int t_size = t.length();
		if (s_size < t_size || !t_size) return 0;
		// dp[i][j] stands for number of distinct subsequences of T.substr(0, j+1) in S.substr(0, i+1)
		vector<vector<int>> dp(s_size, vector<int>(t_size, 0));
		for (int j = 0; j < t_size; j++){
			for (int i = j; i < s_size; i++){
				if (s[i] == t[j]) {
					if (i == 0) dp[i][j] = 1;
					else dp[i][j] = (j == 0 ? 1 : dp[i-1][j-1]) + dp[i-1][j];
				}else {
					if (i == 0) dp[i][j] = 0;
					else dp[i][j] = dp[i-1][j];
				}
			}
		}
		return dp[s_size-1][t_size-1];
    }
};


class Solution{
public:
  int numDistinct(string s, string t){
    int sSize = s.size();
    int tSize = t.size();
    if (sSize < tSize || !tSize) return 0;

    // dp[i][j] means num of subsequence from s(0, i-1) in t(0, j-1)
    vector<vector<int>> dp(sSize + 1, vector<int>(tSize + 1, 0));
    for (int i = 0; i <= sSize; i++)
      dp[i][0] = 1;

    for (int j = 1; j <= tSize; j++){
      for (int i = j; i <= sSize; i++){
        if (s[i-1] == t[j-1])
          dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        else
          dp[i][j] = dp[i-1][j];
      }
    }
    return dp[sSize][tSize];
  }
};