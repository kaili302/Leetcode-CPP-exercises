/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
    	int idx = s.size() - 1;
    	int wordLen = 0;

    	while (idx >= 0){
    		if (s[idx] == ' '){
    			if (wordLen != 0) return wordLen;
    		}else wordLen++;
    		idx--;
    	}
    	return wordLen;
    }
};