/*
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly 
once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]
You should return the indices: [0,9].

*/

class Solution {
private:
	bool matchWords(string s, int idx, unordered_map<string, int> hashmap){
		while (idx + 2 < s.size() && hashmap.size()){
			if (hashmap.count(s.substr(idx, 3))){ 
				if (--hashmap[s.substr(idx, 3)] == 0)
					hashmap.erase(s.substr(idx, 3));
			}else return false;
			idx += 3;
		}
		return hashmap.empty();
	}
public:
    vector<int> findSubstring(string s, vector<string>& words) {
		unordered_map<string, int> hashmap;
		for (auto& word : words) {
			if (hashmap.count(word)) hashmap[word]++;
			else hashmap.emplace(word, 1);
		}        
		int wordsLen = words[0].size() * words.size();
		vector<int> result;
		for (int i = 0; i - 1 + wordsLen < s.size(); i++){
			if (hashmap.count(s.substr(i, 3)) && matchWords(s, i, hashmap)) 
				result.push_back(i);
		}
		return result;
    }
};


class Solution{
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordsNum = words.size();
        if (!wordsNum) return {};
        int wordSize = words[0].size();

        unordered_map<string, int> targetMap;
        for (auto& word : words){
            if (targetMap.count(word)) targetMap[word]++;
            else targetMap.emplace(word, 1);
        }

        vector<int> result;
        for (int offset = 0; offset < wordSize; offset++){
            unordered_map<string, int> currMap;
            int count = 0;
            for (int j = offset; j + wordSize - 1 < s.size(); j += wordSize){
                string currWord = s.substr(j, wordSize);
                if (targetMap.count(currWord)){
                    if (!currMap.count(currWord)){
                        currMap.emplace(currWord, 1);
                        count++;
                    }else{
                        if (currMap[currWord] < targetMap[currWord]){
                            currMap[currWord]++;
                            count++;
                        }else{
                            // need to remove the first occurance of currWord and words before.
                            int left = j - count * wordSize;
                            while (s.substr(left, wordSize) != currWord){
                                currMap[s.substr(left, wordSize)]--;
                                count--;
                                left += wordSize;
                            }
                        }
                    }
                    if (count == words.size())
                        result.push_back(j - wordSize * (count - 1));
                }else{
                    count = 0;
                    currMap.clear();
                }
            }
        }
        return result;
    }
};                