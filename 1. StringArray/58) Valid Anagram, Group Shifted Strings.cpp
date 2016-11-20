/*
Given two strings s and t, write a function to determine if t is an anagram of s.
For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
    	if (s.size() != t.size()) return false;

  		vector<int> alphabet(26, 0);
  		for (int i = 0; i < s.size(); i++)
  			alphabet[s[i] - 'a']++;

		for (int i = 0; i < t.size(); i++){
  			if(--alphabet[t[i] - 'a'] < 0)
  				return false;
  		}
  		return true;
    }
};


/*
Given a string, we can "shift" each of its letter to its successive letter, 
for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence: "abc" -> "bcd" -> ... -> "xyz".
Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence, return:

[
  ["abc","bcd","xyz"],
  ["az","ba"],
  ["acef"],
  ["a","z"]
]
*/

class Solution{
private:
    void convert(string& str){
        char c = str[0];
        for (int i = 0; i < str.size(); i++){
            str[i] = (str[i]  - c + 26) % 26 + 'a';
        }
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashmap;

        for (auto& str : strings){
            string key = str;
            convert(key);
            if (!hashmap.count(key)) 
                hashmap.insert({key, {}});
            hashmap[key].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++)
            ret.push_back(it->second);
        return ret;
    }
};
