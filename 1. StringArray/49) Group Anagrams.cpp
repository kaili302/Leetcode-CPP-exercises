/*
Given an array of strings, group anagrams together.
 ["eat", "tea", "tan", "ate", "nat", "bat"], 
return 
[
  ["ate", "eat","tea"],
  ["nat","tan"],
  ["bat"]
]
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        
        for (auto& str : strs){
        	string key = str;
        	sort(key.begin(), key.end());
        	if (!hashmap.count(key)) 
        		hashmap.insert({key, {}});
        	hashmap[key].push_back(str);
        }
        
        vector<vector<string>> result;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++){
        	result.push_back(it->second);
        }

        return result;
    }
};


