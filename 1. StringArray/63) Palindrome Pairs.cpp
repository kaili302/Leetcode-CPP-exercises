/*
Given a list of unique words. Find all pairs of distinct indices (i, j) in the given list, 
so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.

Example 1:
Given words = ["bat", "tab", "cat"]
Return [[0, 1], [1, 0]]
The palindromes are ["battab", "tabbat"]
Example 2:
Given words = ["abcd", "dcba", "lls", "s", "sssll"]
Return [[0, 1], [1, 0], [3, 2], [2, 4]]
The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
*/
class Solution {
private:
	bool isPal(string str){
		int lo = 0, hi = str.size() - 1;
		while (lo < hi && str[lo] == str[hi]){
			lo++;
			hi--;
		}
		return lo >= hi;
	}
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
		vector<vector<int>> result;
		for (int i = 0; i < words.size(); i++){
			for (int j = i + 1; j < words.size(); j++){
				if (isPal(words[i] + words[j])) 
					result.push_back({i, j});
				if (isPal(words[j] + words[i])) 
					result.push_back({j, i});
			}
		}        
		return result;
    }
};


// we want to quickly match word, use a trie!!!
// 面试的时候 见到 string, 优先想到 trie
struct Trie{
	char c;
	Trie* kids[26] = {0};
	int idx = -1;
	Trie(char val) : c{val}{}
};

// we want to quickly match word, use a trie!!!
// 面试的时候 见到 string, 优先想到 trie
struct Trie{
    char c;
    Trie* kids[26] = {0};
    int idx = -1;
    Trie(char val) : c{val}{}
};


class Solution {
private:
    Trie* pRoot;
    
    vector<Trie*> toCollect;
    Trie* createNode(char c){
        toCollect.push_back(new Trie(c));
        return toCollect.back();
    }

    void buildTrie(vector<string>& words){
        for (int j = 0; j < words.size(); j++){
            string& word = words[j];
            Trie* pCurr = pRoot;
            for (int i = 0; i < word.size(); i++){
                if (!pCurr->kids[word[i]-'a']) 
                    pCurr->kids[word[i]-'a'] = createNode(word[i]);
                pCurr = pCurr->kids[word[i]-'a'];
            }
            pCurr->idx = j;
        }
    }

    bool isPal(const string& str, int hi){
        int lo = 0;
        while (lo < hi && str[lo] == str[hi]){
            lo++; hi--;
        }
        return lo >= hi;
    }

public:
    ~Solution(){/*free trie*/}

    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> result;
        pRoot = createNode('0');
        buildTrie(words);
        
        for (int i = 0; i < words.size(); i++){
            // match word in trie
            string& word = words[i];
            Trie* pCurr = pRoot;
            if (pRoot->idx != -1 && i != pRoot->idx && isPal(word, word.size() - 1)){
                result.push_back({pRoot->idx, i});result.push_back({i, pRoot->idx});
            }
            for (int j = word.size() - 1; j >= 0; j--){
                if (pCurr->kids[word[j]-'a']){
                    int idx = pCurr->kids[word[j]-'a']->idx;
                    if (idx != -1){
                        if (idx == i) continue;
                        if (isPal(word, j - 1)) 
                            result.push_back({idx, i});
                    }
                    pCurr = pCurr->kids[word[j]-'a'];
                }else break;
            }
        }
        return result;
    }
};
