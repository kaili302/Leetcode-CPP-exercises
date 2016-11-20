/*
Given a pattern and a string str, find if str follows the same pattern.
Here follow means a full match, such that there is a bijection between a 
letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains
 lowercase letters separated by a single space.
*/

typedef unordered_map<string, string> HashMap_t;
class Solution {
private:
    void nextWord(const string& str, string& wordOut, int& start){
        while (start < str.size() && str[start] == ' ') 
            start++;
        int end = start + 1;
        while (end < str.size() && str[end] != ' ') 
            end++;      
        wordOut = str.substr(start, end - start);
        start = end;
    }
public:
    bool wordPattern(string pattern, string str) {
        HashMap_t hashmap1;
        HashMap_t hashmap2;
        string word;
        int wordIdx = 0;
        for (int i = 0; i < pattern.size(); i++){
            string c = to_string(pattern[i]);
            nextWord(str, word, wordIdx);

            if (word == "") return false;

            if (hashmap1.count(c) || hashmap2.count(word)){
                if (!hashmap1.count(c) || !hashmap2.count(word) || 
                    hashmap1[c] != word || hashmap2[word] != c)
                    return false;
            }else{
                hashmap1.insert({c, word});
                hashmap2.insert({word, c});
            }
        }
        nextWord(str, word, wordIdx);
        return word.empty();
    }
};


/*
This is the extension problem of Word Pattern I.

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter 
in pattern and a non-empty substring in str.

Examples:
pattern = "abab", str = "redblueredblue" should return true.
pattern = "aaaa", str = "asdasdasdasd" should return true.
pattern = "aabb", str = "xyzabcxzyabc" should return false.
*/


class Solution {
private:
    bool wordPattern(string pattern, string str, 
        unordered_map<char, string>& ptn2word, 
        unordered_map<string, char>& word2ptn) {

        if (pattern.empty() && str.empty()) return true;
        else if (pattern.empty() || str.empty()) return false;

        char c = pattern[0];
        
        if (ptn2word.count(c)){
            string& word = ptn2word[c];
            if (str.find(word) != 0 || !word2ptn.count(word) || word2ptn[word] != c)
                return false;
            return wordPattern(pattern.substr(1), str.substr(word.size()), ptn2word, word2ptn);
        }else{
            for (int wordLen = 1; wordLen <= str.size(); wordLen++){
                // match c and str.substr(0, wordLen)
                string word = str.substr(0, wordLen);
                if (word2ptn.count(word)) continue; // this word is already macthed to a pattern
                word2ptn.insert({word, c});
                ptn2word.insert({c, word});
                if (wordPattern(pattern.substr(1), str.substr(word.size()), ptn2word, word2ptn))
                    return true;
                word2ptn.erase(word);
                ptn2word.erase(c);
            }
        }
        return false;
    }

public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> ptn2word;
        unordered_map<string, char> word2ptn;
        return wordPattern(pattern, str, ptn2word, word2ptn);
    }
};
