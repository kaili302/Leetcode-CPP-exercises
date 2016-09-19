/** 
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?
*/


#include <ctype.h>
#include <algorithm>

using namespace std;

class Solution {
public:
	void reverseWords(string& s) {
		reverse (s, 0, s.length()-1);
		int left=0; // first non-zero charater
		for (int i=0; i<s.length(); i++) {
			if (i==s.length()-1 || isspace(s[i+1])) {
				reverse(s, left, i);
				left = i+2;
			}
		}
	}

	void reverse (string& s, int lo, int hi) {
		if (lo<0 || hi >= s.length()) return;

		while (lo < hi) {
			swap (s[lo++], s[hi--]);
		}
	}
};
