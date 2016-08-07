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
LeetCode – Word Ladder II
 
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that: 1) Only one letter can be changed at a time, 2) Each intermediate word must exist in the dictionary.

For example, given: start = "hit", end = "cog", and dict = ["hot","dot","dog","lot","log"], return:

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
*/


using std::string;
using std::vector;
using std::queue;


struct WordNode {
    WordNode *prev;
    string word;
    WordNode(string iword, WordNode* iprev):word{iword}, prev{iprev}{}
};
class Solution {
private:
    void pushToQueue(queue<WordNode*> &bfsQueue, deque<WordNode*> &toFree, string &word, WordNode *prev=nullptr) {
        bfsQueue.push(new WordNode{word, prev});
        toFree.push_back(bfsQueue.back());
    }

    void buildLadder(WordNode *pNode, vector<string> &ladder) {
        while (pNode) {
            ladder.push_back(pNode->word);
            pNode = pNode->prev;
        }
        reverse(ladder.begin(), ladder.end());
    }

    void freeNodes(deque<WordNode*> &toFree){
        for(auto &pNode:toFree) delete pNode;
    }
public:
vector<vector<string>> findLadders(string beginWord, string endWord, std::unordered_set<string> &wordList) {
        vector<vector<string>> result;
        if (beginWord.length()!=endWord.length()) return result;
        if (wordList.count(beginWord)) wordList.erase(beginWord);
        wordList.insert(endWord);

        queue<WordNode*> bfsQueue;
        deque<WordNode*> toFree;
        pushToQueue(bfsQueue, toFree, beginWord);
        bool isLadderFound=false;

        while (bfsQueue.size()&&!isLadderFound){
            int size=bfsQueue.size();
            vector<string> toRemoveFromDict;
            for(int i=0; i<size; i++){
                WordNode* pCurrNode=bfsQueue.front();
                string &currWord=pCurrNode->word;
                if(currWord==endWord) {
                    isLadderFound=true;
                    break;
                }

                bfsQueue.pop();
                for (int j=0; j<currWord.length(); j++){
                    char tmp=currWord[j];
                    for (char c='a'; c<='z'; c++) {
                        currWord[j]=c;
                        if(wordList.count(currWord)) {
                            pushToQueue(bfsQueue, toFree, currWord, pCurrNode);
                            toRemoveFromDict.push_back(currWord);
                        }
                    }
                    currWord[j]=tmp;
                }
            }
            //remove words has been used as ladder
            for (auto &word:toRemoveFromDict) wordList.erase(word);
            toRemoveFromDict.clear();
        }
        while(bfsQueue.size()){
            if(bfsQueue.front()->word==endWord) {
                result.push_back(vector<string>{});
                buildLadder(bfsQueue.front(), result.back());
            }            
            bfsQueue.pop();
        }
        freeNodes(toFree);
        return result;
    }
};
