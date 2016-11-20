//find the longest string that is a substring of two or more strings.
//The LCS of "ABABC" and "ABCBA" is "ABC"

int LCS(string s, string t){
    int ssize = s.size();
    int tsize = t.size();
    int maxLen = 0;
    vector<vector<int>> dp(ssize + 1, vector<int>(tsize + 1, 0));
    for (int i = 1; i <= ssize; i++){
        for (int j = 1; j <= tsize; j++){
            if (s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }   
    return maxLen;
}