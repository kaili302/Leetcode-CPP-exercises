/*
search(word) can search a literal word or a regular expression string containing 
only letters a-z or .. A . means it can represent any one letter.
*/

class TrieNode{
public:
	TrieNode* kids[26] = {0};
	bool isLeaf = false;
	char val;
	TrieNode(char v): val{v}{}
};

class WordDictionary {
private:
	TrieNode* root;
	deque<TrieNode*> toDelete;

	TrieNode* createTrieNode(char c = ' '){
		toDelete.push_back(new TrieNode{c});
		return toDelete.back();
	}

	bool search(string word, int idx, TrieNode* curr) {
		for (int i = idx; i < word.length(); i++){
			if (word[i] == '.'){
				for (int c = 0; c < 26; c++){
					if (curr->kids[c] && search(word, i+1, curr->kids[c])) return true; 
				}
				return false;
			}else{
				if (!curr->kids[word[i]-'a']) return false;
	        	curr = curr->kids[word[i]-'a'];	
			}
        }
        return curr->isLeaf;
	}

public:
	WordDictionary(){
		root = createTrieNode(); 
	}

	~WordDictionary(){
		for (auto &pNode: toDelete)
			delete pNode;
	}

    void addWord(string word) {
		TrieNode* curr = root;
		for (int i = 0; i< word.length(); i++ ){
			if (!curr->kids[word[i]-'a'])
				curr->kids[word[i]-'a'] = createTrieNode(word[i]);
			curr = curr->kids[word[i]-'a'];
		}
		curr->isLeaf = true;
    }

    bool search(string word) {
		return search(word, 0, root);
    }
};
