/*
Given a 2D board and a list of words from the dictionary, find all words in the board.
Each word must be constructed from letters of sequentially adjacent cell, 
where "adjacent" cells are those horizontally or vertically neighboring. 
The same letter cell may not be used more than once in a word. For example,
Given words = ["oath","pea","eat","rain"] and board =
[
  ['o','a','a','n'],
  ['e','t','a','e'],
  ['i','h','k','r'],
  ['i','f','l','v']
]
Return ["eat","oath"].
*/

// build word trie 
class TrieNode{
public:
	char m_val;
	string m_word;
	TrieNode* m_kids[26] = {0};
	TrieNode () {
	}
	TrieNode(int val): m_val{val}, m_word{""}{}
};


class Solution {
private:
	deque<TrieNode*> toDelete;
	TrieNode* createTrieNode(char c =  ' '){
		toDelete.push_back(new TrieNode(c)); 
		return toDelete.back();
	}

	TrieNode* buildWordsTrie(vector<string>& words){
		TrieNode* root = createTrieNode();
		for (auto& word : words){
			TrieNode* curr = root;
			for (int i = 0; i < word.length(); i++){
				if (!curr->m_kids[word[i]-'a'])	
					curr->m_kids[word[i]-'a'] = createTrieNode(word[i]);			
				curr = curr->m_kids[word[i]-'a'];
			}
			curr->m_word = word;
		}
		return root;
	}

	const vector<pair<int, int>> dirs{{-1, 0},{1, 0},{0, -1},{0, 1}};
	void findWords(vector<vector<char>>& board, int r, int c, int HE, int WI, TrieNode* curr, unordered_set<string>& result) {
		if (!curr) return;

		// curr trie node is leaf
		if (curr->m_word != "") {
			result.insert(curr->m_word);
		}

		char tmp = board[r][c];
		board[r][c] = '#';
		// kid[idx-'a'] is not null
		for (auto &dir : dirs){
			int x = r + dir.first, y = c + dir.second; 
			if (x < 0 || x >= HE || y < 0 || y >= WI || board[x][y]=='#') continue;
			findWords(board, x, y, HE, WI, curr->m_kids[board[x][y]-'a'], result);				
		}
		board[r][c] = tmp;
	}

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = buildWordsTrie(words);
        int HE = board.size();
        int WI = board[0].size();

        unordered_set<string> result;
        for (int r = 0; r < HE; r++){
        	for (int c = 0;  c < WI; c++){
        		findWords(board, r, c, HE, WI, root->m_kids[board[r][c]-'a'], result);
        	}
        }
        return {result.begin(), result.end()};
    }
};



