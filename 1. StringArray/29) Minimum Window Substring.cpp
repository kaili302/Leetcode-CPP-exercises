/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T 
in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"
Minimum window is "BANC".
*/


class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";
        
        unordered_map<char, int> hashmap;
        for (int i = 0; i < t.size(); i++){
            if(hashmap.count(t[i])) hashmap[t[i]]++;
            else hashmap.emplace(t[i], 1);
        }
        
        unordered_map<char, int> currMap;
        int count = 0;
        int left = 0, minLeft = 0, minRight = s.size() - 1;
        
        for (int i = 0; i < s.size(); i++){
            if (hashmap.count(s[i])){
                if (!currMap.count(s[i])){
                    currMap.emplace(s[i], 1);
                    count++;
                }else{
                    currMap[s[i]]++;
                    if (currMap[s[i]] <= hashmap[s[i]]) count++;
                }
            }
            if (count == t.size()){
                while(!currMap.count(s[left]) || currMap[s[left]] > hashmap[s[left]]){
                    if (currMap.count(s[left])) currMap[s[left]]--;
                    left++;
                }
                if (minRight - minLeft > i - left){
                    minRight = i;
                    minLeft = left;
                }
            }
        }
        
        if (count < t.size()) return "";
        return s.substr(minLeft, minRight - minLeft + 1);
    }
};