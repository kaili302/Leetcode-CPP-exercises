/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",

Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
*/
class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int sLen = s.length();
        vector<vector<bool>> isPal(sLen, vector<bool>(sLen, false));
        for (int i = sLen - 1; i >= 0; i--){
        	for (int j = i; j < sLen; j++){
        		if (s[i] == s[j] && (i + 1 >= j || isPal[i+1][j-1]))
        			isPal[i][j] = true;
        	}
        }

        vector<int> minCut(sLen + 1, sLen);
        minCut[0] = -1;
        for (int i = 0; i < sLen; i++){
        	for (int j = i; j >=0; j--){
        		if (isPal[j][i]) minCut[i+1] = min(minCut[i+1], 1 + minCut[j]);
        	}
        }
        return minCut[sLen];
    }
};
