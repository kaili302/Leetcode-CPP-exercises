/*
Merge k sorted linked lists and return it as one sorted list. 
Analyze and describe its complexity. 
The simplest solution is using PriorityQueue. The elements of the priority queue are ordered according to their natural ordering, or by a comparator provided at the construction time (in this case).
*/
class cmp{
public:
    bool operator()(ListNode *&pNode1, ListNode *&pNode2){
    	return pNode1->val > pNode2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
    	int size = lists.size();
    	if (size == 0) return nullptr;

    	priority_queue<ListNode*, vector<ListNode*>, cmp> minHeap;
    	for (auto &tmpList : lists) 
    		if (tmpList) minHeap.push(tmpList);

    	ListNode dummy{0};
    	ListNode *pHead = &dummy;

    	while(minHeap.size()) {
    		ListNode *pNode = minHeap.top();
    		minHeap.pop();
    		pHead->next = pNode;
    		pHead = pHead->next;
    		pNode = pNode->next;
    		if (pNode) minHeap.push(pNode);
    	}

    	return dummy.next;
    }
};