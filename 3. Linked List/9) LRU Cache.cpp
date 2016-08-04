/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Subscribe to see which companies asked this question
*/


struct LRUNode {
	LRUNode *next;
	LRUNode *prev;
	int key;
	int val;
	LRUNode():key{0}, val{0}, next{nullptr}, prev {nullptr}{} 
	LRUNode(int ikey, int ival):key{ikey}, val{ival}, next{nullptr}, prev {nullptr}{}
};

class LRUCache{
private:
	std::unordered_map<int, LRUNode> m_map;
	LRUNode m_head;
	LRUNode m_tail;
	int m_capacity;

	bool full() {
		return m_capacity == m_map.size();
	}

	void removeLast() {
		LRUNode *pNode=m_tail.prev;
		pNode->next->prev=pNode->prev;
		pNode->prev->next=pNode->next;
		m_map.erase(pNode->key);
	}

	void rise(int key) {
		if (!m_map.count(key)) return;
		LRUNode *pNode=&m_map[key];
		if (pNode->next !=nullptr){
			// remove from original position
			pNode->next->prev=pNode->prev;
			pNode->prev->next=pNode->next;
		}
		// insert at head position
		m_head.next->prev=pNode;
		pNode->next=m_head.next;
		pNode->prev=&m_head;
		m_head.next=pNode;
	}


public:
    LRUCache(int capacity): m_capacity{capacity}, m_tail{}, m_head{}, m_map{}{
    	m_head.next=&m_tail;
    	m_tail.prev=&m_head;
    }
    
    int get(int key) {
    	int val=-1;
    	if (m_map.count(key)) {
    		val=m_map[key].val;
    		rise(key);
    	}
    	return val;
    }
    
    void set(int key, int value) {
    	if (m_map.count(key)==0) {
    		if (full()) removeLast();
    		m_map.insert(std::make_pair(key, LRUNode{key, value}));
    	}else m_map[key].val=value;
    	rise(key);
    }
};



