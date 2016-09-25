/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() <= 1) return s.size();
        unordered_map<char, int> hashmap;
        hashmap.emplace(s[0], 0);
        int left = 0;
        int maxLen = 1;
        for (int i = 1; i < s.size(); i++){
            if (hashmap.count(s[i])){
                if(hashmap[s[i]] >= left) left = hashmap[s[i]] + 1;
                hashmap[s[i]] = i;
            }else hashmap.emplace(s[i], i);
            maxLen = max(maxLen, i - left + 1);
            cout << maxLen << " " << left << endl;
        }
        return maxLen;
    }
};
