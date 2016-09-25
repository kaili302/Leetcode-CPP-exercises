/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.
*/
class Solution {
private:
  char getChar(char& c){
    if (c <= '9' && c >= '0') return c;
    else if (c <= 'Z' && c >= 'A') return c - 'A' + 'a';
    else if (c <= 'z' && c >= 'a') return c;
    else return 0;
  }
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        int lo = 0, hi = s.size() - 1;

        while (lo < hi){
          char loC = getChar(s[lo]);
          char hiC = getChar(s[hi]);
          if (!loC) lo++;
          else if (!hiC) hi--;
          else{
            if (loC != hiC) return false;
            lo++; 
            hi--;
          }
        }
        return true;
    }
};