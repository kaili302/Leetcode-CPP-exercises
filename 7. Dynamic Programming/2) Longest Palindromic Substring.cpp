/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    /* time out */
    string longestPalindrome(string s) {
    	int size = s.length();
    	if (!size) return s;
        // isPalin[i][j] means whether s(i, j) is palindromic
        vector<vector<bool>> isPalin(size, vector<bool>(size, false));
        int maxLen = 1;
        int maxIdx = 0;
        for (int i = 0; i < size; i++){
        	for (int j = i; j < size; j++){
        		if (i == j || (s[j] == s[i] && (i+1 == j || isPalin[i+1][j-1]))){
        			isPalin[i][j] = true;
        			if (j - i + 1 > maxLen){
        			    maxLen = j - i + 1;
        			    maxIdx = i;
        			}
        		}
        	}
        }
        return s.substr(maxIdx, maxLen);
    }

    /* straight forward solution */
    string longestPalindrome(string s) {
        int size = s.length();
        if (!size) return s;
        int maxLen = 1;
        int maxIdx = 0;
        for (int i = 0; i <= size-maxLen/2; i++){
            int lo = i - 1;
            int hi = i + 1;
            while (lo >=0 && hi < size && s[lo] == s[hi]){
                lo--;
                hi++;
            }
            if (maxLen < hi - lo - 1){
                maxLen = hi - lo -1;
                maxIdx = lo + 1;
            }
            lo = i;
            hi = i + 1;
            while (lo >=0 && hi < size && s[lo] == s[hi]){
                lo--;
                hi++;
            }
            if (maxLen < hi - lo - 1){
                maxLen = hi - lo -1;
                maxIdx = lo + 1;
            }
        }
        return s.substr(maxIdx, maxLen);
    }
};