class TrieNode {
public:
    char m_val;
    bool m_isLeaf = false;
    TrieNode* m_kids[26] = {0};
    TrieNode(char c) : m_val{c}{ }
};


class Trie {
private:
    TrieNode* root;
    deque<TrieNode*> toDelete;

    TrieNode* createTrieNode(char c = ' '){
        TrieNode* pNode = new TrieNode{c};
        toDelete.push_back(pNode);
        return pNode;
    }

public:
    Trie() {
        root = createTrieNode();
    }
    ~Trie(){
        for (auto& pNode : toDelete) 
            delete pNode;
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++){
            if (!curr->m_kids[word[i]-'a']) 
                curr->m_kids[word[i]-'a'] = createTrieNode(word[i]);
            curr = curr->m_kids[word[i]-'a'];
        }
        curr->m_isLeaf = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (int i = 0; i < word.length(); i++){
            if (!curr->m_kids[word[i]-'a']) return false;
            curr = curr->m_kids[word[i]-'a'];
        }
        return curr->m_isLeaf;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i = 0; i < prefix.length(); i++){
            if (!curr->m_kids[prefix[i]-'a']) return false;
            curr = curr->m_kids[prefix[i]-'a'];
        }
        return true;
    }
};