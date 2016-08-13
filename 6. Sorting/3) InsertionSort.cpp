/*
Sort a linked list using insertion sort.
*/


class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
		 if (head==nullptr) return nullptr;
		 ListNode dummy{0};
		 dummy.next = head;
		 head = &dummy;

		 ListNode *pCurr = head->next;
		 ListNode *pPrev = head;

		 while (pCurr !=nullptr) {
		 	ListNode *pNode = head;
		 	while (pNode->next->val < pCurr->val) {
		 		pNode = pNode->next;
		 	}
		 	if (pNode->next == pCurr){
		 	    pPrev = pCurr;
		 	    pCurr = pCurr->next;
		 	}else{
    	 		pPrev->next = pCurr->next;
    		 	pCurr->next = pNode->next;
    		 	pNode->next = pCurr;
    		 	pCurr = pPrev->next;
		 	}
		 }
		 return head->next;
    }
};