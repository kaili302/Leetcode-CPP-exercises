/** 
Given two strings s and t, determine if they are isomorphic. 
Two strings are isomorphic if the characters in s can be replaced to get t.
For example,"egg" and "add" are isomorphic, "foo" and "bar" are not.

Analysis We can define a map which tracks the char-char mappings. 
If a value is already mapped, it can not be mapped again.
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length() || s.empty()) return false;

        const int ASCIISIZE = 256;
        int undefined = -1;
        int dict[ASCIISIZE]{undefined};
        int dictCheck[ASCIISIZE]{undefined};

        for (int i=0; i<s.length(); i++) {
        	if (dict[s[i]] == t[i]) continue;
        	else if (dict[s[i]] == undefined && dictCheck[t[i]] == undefined) {
    			dict[s[i]] = t[i];
    			dictCheck[t[i]] = s[i];
        	}else return false;
        }
        return true;
    }
};


