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
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for (int i = 0; i <= word1.size(); i++){
            for (int j = 0; j <= word2.size(); j++){
                if (!i) dp[i][j] = j;
                else if (!j) dp[i][j] = i;
                else if (word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = min(min(dp[i][j-1], dp[i-1][j-1]), dp[i-1][j]) + 1;
            }
        }
        return dp.back().back();
    }
};


//o(n) space
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word1.size() + 1, 0);
        for (int j = 0; j <= word2.size(); j++){
            int prev = dp[0];
            for (int i = 0; i <= word1.size(); i++){
                int tmp = dp[i];
                if (!j) dp[i] = i;
                else if (!i) dp[i] = j;
                else if (word1[i-1] == word2[j-1]) dp[i] = prev;
                else dp[i] = min(prev, min(dp[i-1], dp[i])) + 1;
                prev = tmp;
            }
        }
        return dp.back();
    }
};