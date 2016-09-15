class cmp{
public:
	bool operator()(ListNode* pNode1, ListNode* pNode2) const{
		return pNode1->val > pNode2->val;
	}
};

class Solution{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists){
		if (lists.empty()) return nullptr;
		priority_queue<ListNode*, deque<ListNode*>, cmp> minHeap;
		for (auto& list : lists){
			if (list) minHeap.push(list);
		}

		ListNode dummy{0};
		ListNode* pHead = &dummy;

		while(minHeap.size()){
			ListNode* pNode = minHeap.top();
			minHeap.pop();
			pHead->next = pNode;
			pHead = pHead->next;
			pNode = pNode->next;
			if (pNode) minHeap.push(pNode);
		}

		return dummy.next;
	}
};