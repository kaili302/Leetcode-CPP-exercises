/*
The longest common subsequence (LCS) problem is the problem of finding the longest subsequence common to 
all sequences in a set of sequences (often just two sequences).
The LCS of "ABABC"，"BABCA" and "ABCBA" is "ABC"
*/

class Solution{
public:
    int LCS(string s, string t){
        if (s.size() * t.size() == 0) return 0;
        // let dp[i][j] be the LCS between s(0, i) and t(0, j)
        // if s[i] == t[j] dp[i][j] = max(dp[i-1][j-1] + 1, dp[i-1][j], dp[i][j-1]);
        // if s[i] != t[j] dp[i][j] = max(dp[i-1][j], dp[i][j-1]);

        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for (int i = 1; i <= s.size(); i++){
            for (int j = 1; j <= t.size(); j++){
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (s[i-1] == t[j-1]) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
        return dp[s.size()][t.size()];
    }
};
