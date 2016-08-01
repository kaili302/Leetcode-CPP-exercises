/**
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that only one letter can be changed at a time and each intermediate word must exist in the dictionary. For example, given:

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
One shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog", the program should return its length 5.
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
    	if (wordList.empty()) return 0;
    	queue<string> queue{};
    	
    	int count = 1;
    	queue.push(beginWord);

    	while (!queue.empty()) {
    		count++;
			int size = queue.size();
			for (int i=0; i<size; i++) {
				string &word = queue.front();

				for (int j=0; j<word.length(); j++) {
					char tmp = word[j];
					for (char c='a'; c<='z'; c++) {
						word[j] = c;
						if(wordList.count(word) > 0) {
							if (word == endWord) return count;
							queue.push(string(word));
							wordList.erase(word);
						}
					}
					word[j] = tmp;
				}

				queue.pop();
			}
    	}
    	return 0;
    }
};


/** 
LeetCode – Word Ladder II (Java)
 
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that: 1) Only one letter can be changed at a time, 2) Each intermediate word must exist in the dictionary.

For example, given: start = "hit", end = "cog", and dict = ["hot","dot","dog","lot","log"], return:

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/
struct WordNode {
    WordNode *prev;
    string word;
};

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string> &wordList) {
        vector<vector<string>> result;
        if (wordList.empty() || beginWord.length() != endWord.length()) return result;
        if (wordList.count(beginWord)>0) wordList.erase(beginWord);        
        wordList.insert(endWord);

        vector<WordNode> nodelist;
        queue<WordNode*> queue;
        nodelist.push_back(WordNode{nullptr, beginWord});
        queue.push(&nodelist.back());
        vector<string> toRemove;
        bool ladderFound = false;

        while (!queue.empty()) {
             printQueue(queue);
            int size = queue.size();
            for (int i=0; i<size; i++) {
                WordNode *pWordNode = queue.front();
                queue.pop();    // pWordNode is store in nodelist
                string word = pWordNode->word;
                if(word == endWord) {
                    vector<string> ladder;
                    getWordList(pWordNode, ladder);
                    result.push_back(ladder);
                }else if (ladderFound) continue;

                for (int j=0; j<word.length(); j++) {
                    char tmp = word[j];
                    for (char c='a'; c<='z'; c++) {
                        word[j] = c;
                        if (wordList.count(word) >0) {
                            toRemove.push_back(word);
                            nodelist.push_back(WordNode{&(*pWordNode), word});
                            queue.push(&nodelist.back());
                        }
                    }
                    word[j] = tmp;
                }
            }
            for (int i=0; i<toRemove.size(); i++) {
                wordList.erase(toRemove[i]);
            }
            toRemove.clear();
        }
        return result;
    }


    void getWordList(WordNode *wordNodeIn, vector<string> &wordListOut) {
        while (wordNodeIn) {
            wordListOut.push_back(wordNodeIn->word);
            wordNodeIn = wordNodeIn->prev;
        }
        reverse(wordListOut.begin(), wordListOut.end());
    }

    void printQueue(queue<WordNode*> queue) {
        cout << "print queue: " <<endl;
        while (!queue.empty()) {
            WordNode *wn = queue.front();
            vector<string> wordList;
            getWordList(wn, wordList);
            for (auto &word: wordList) {
                cout << word <<'\t';
            }
            queue.pop();
        }
        cout << endl;
    }
};
































