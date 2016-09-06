/*
Given two words word1 and word2, find the minimum number of steps 
required to convert word1 to word2. (each operation is counted as 1 step.)
You have the following 3 operations permitted on a word:
a) Insert a character
b) Delete a character
c) Replace a character
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.length();
        int size2 = word2.length();
        if (!size1 || !size2) return abs(size1 - size2);

        // dp[i][j] stands for the edit distance between word1.substr(0, i) and word2.substr(0, j)
        vector<vector<int>> dp(size1+1, vector<int>(size2+1, 0));
        for (int i = 0; i <= size1; i++) dp[i][0] = i;
        for (int j = 0; j <= size2; j++) dp[0][j] = j;
        
        for (int j = 1; j <= size2; j++){
            for (int i = 1; i <= size1; i++){
                if (word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }else{
                    dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                }                   
            }
        }
        return dp[size1][size2];
    }
};