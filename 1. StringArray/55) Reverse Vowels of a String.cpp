/*
Write a function that takes a string as input and reverse only the vowels of a string.

Example 1:
Given s = "hello", return "holle".

Example 2:
Given s = "leetcode", return "leotcede".

Note:
The vowels does not include the letter "y".
*/
class Solution {
private:
	bool isVowel(const char& c){
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
		       c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}
public:
    string reverseVowels(string s) {
        // a e i o u
    	int lo = 0, hi = s.size() - 1;
    	while (lo < hi){
    		while (lo < s.size() && !isVowel(s[lo])) lo++;
    		if (lo > hi) break;
    		while (hi >= lo && !isVowel(s[hi])) hi--;
    		swap(s[lo++], s[hi--]);
    	}
    	return s;
    }
};