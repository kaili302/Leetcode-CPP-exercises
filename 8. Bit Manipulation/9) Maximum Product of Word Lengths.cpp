/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) 
where the two words do not share common letters. You may assume that each word will contain 
only lower case letters. If no such two words exist, return 0.

Example 1:
Given ["abcw", "baz", "foo", "bar", "xtfn", "abcdef"]
Return 16
The two words can be "abcw", "xtfn".

Example 2:
Given ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
Return 4
The two words can be "ab", "cd".

Example 3:
Given ["a", "aa", "aaa", "aaaa"]
Return 0
No such pair of words.
*/

class Solution {
public:
    int maxProduct(vector<string>& words) {
        // a to z 26 letters, use bitmap, needs 26 bits
        unordered_map<string, uint32_t> dict;
        for (auto &word : words){
            uint32_t bitmap = 0;
            for (int i = 0; i < word.length(); i++){
                bitmap |= 1 << (word[i] - 'a');
            }
            dict.emplace(word, bitmap);
        }

        int maxProduct = 0;
        for (int i = 0; i < words.size(); i++){
            for (int j = i + 1; j < words.size(); j++){
                if ((dict[words[i]] & dict[words[j]]) == 0)
                    maxProduct = max(maxProduct, static_cast<int>(words[i].length() * words[j].length()));
            }
        }
        return maxProduct;
    }
};


// optimize: no need of unordered_map
class Solution {
public:
    int maxProduct(vector<string>& words) {

        vector<uint32_t> bitmap(words.size(), 0);
        
        for (int i= 0; i < words.size(); i++){
            for (int j = 0; j < words[i].length(); j++){
                bitmap[i] |= 1 << (words[i][j] - 'a');
            }
        }

        int maxProduct = 0;
        for (int i = 0; i < words.size(); i++){
            for (int j = i + 1; j < words.size(); j++){
                if ((bitmap[i] & bitmap[j]) == 0)
                    maxProduct = max(maxProduct, static_cast<int>(words[i].length() * words[j].length()));
            }
        }
        return maxProduct;
    }
};