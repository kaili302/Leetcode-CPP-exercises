/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. 
Find and return the shortest palindrome you can find by performing this transformation.
For example, given "aacecaaa", return "aaacecaaa"; given "abcd", return "dcbabcd".
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() <= 1) return s;
        int end = 0;
        for (end = s.size() - 1; end >= 0 ; end--){
            // check if (o, end) is palindrome
            int lo = 0, hi = end;
            while (lo < hi && s[lo] == s[hi]){
                lo++; 
                hi--;
            }
            if (hi <= lo) break; 
        }
        end++;

        string prefix;
        prefix.reserve(s.size() - end);
        for (int i = end; i < s.size(); i++){
            prefix.push_back(s[i]);
        }
        reverse(prefix.begin(), prefix.end());
        return prefix + s;
    }
};