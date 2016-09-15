/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
private:
	RandomListNode* cloneNode(RandomListNode* pNode){
		RandomListNode* pNewNode = new RandomListNode{pNode->label};
		pNewNode->random = pNode->random;
		return pNewNode;
	}
public:
    RandomListNode* copyRandomList(RandomListNode* head) {
    	unordered_map<RandomListNode*, RandomListNode*> mapNodes;
    	
    	RandomListNode dummy{0};
		RandomListNode* pCloneHead = &dummy;

    	RandomListNode* pNode = head;
    	while (pNode){
    		pCloneHead->next = cloneNode(pNode);
    		mapNodes.emplace(pNode, pCloneHead->next);
    		pNode = pNode->next;
    		pCloneHead = pCloneHead->next;
    	}

    	pCloneHead = &dummy;
    	while (pCloneHead->next){
    		pCloneHead->next->random = mapNodes[pCloneHead->next->random];
    		pCloneHead = pCloneHead->next;
    	}

    	return dummy.next;        
    }
};


