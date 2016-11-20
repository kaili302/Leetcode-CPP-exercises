/**
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.
get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. 
When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
Subscribe to see which companies asked this question
*/

struct LRUNode{
    int key;
    int val;
    LRUNode* pPrev = nullptr;
    LRUNode* pNext = nullptr;
    LRUNode(int ikey, int ival) : key {ikey}, val{ival}{}
};

class LRUCache{
    unordered_map<int, LRUNode*> hashmap;
    LRUNode* pHead;
    LRUNode* pEnd;
    int capacity;

    void promot(LRUNode* pNode){
        if (pNode->pNext && pNode->pPrev){
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
        }
        pNode->pNext = pHead->pNext;
        pHead->pNext->pPrev = pNode;
        pHead->pNext = pNode;
        pNode->pPrev = pHead;
    }

    void freeNode(LRUNode* pNode){
        delete pNode;
        pNode = nullptr;
    }

    void remove(LRUNode* pNode){
        if (!pNode || pNode == pHead || pNode == pEnd)
            return;
        hashmap.erase(pNode->key);
        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;
        freeNode(pNode);
    }
    
    bool isFull(){
        return capacity == hashmap.size();
    }

public:
    LRUCache(int icapacity) : capacity{icapacity}{
        pHead = new LRUNode{0, 0};
        pEnd = new LRUNode{0, 0};
        pEnd->pPrev = pHead;
        pHead->pNext = pEnd;
    }

    void set(int key, int val){
        if (hashmap.count(key)){
            hashmap[key]->val = val;
        }else{
            if (isFull())
                remove(pEnd->pPrev);
            hashmap.insert({key, new LRUNode{key, val}});
        }
        promot(hashmap[key]);
    }

    int get(int key){
        if (!hashmap.count(key))
            return -1;
        promot(hashmap[key]);
        return hashmap[key]->val;
    }
};
