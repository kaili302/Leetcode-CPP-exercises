/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example, given 1->1->1->2->3, return 2->3.
*/

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* pHead){
		ListNode dummy{0};
		ListNode* pPivot = &dummy;
		pPivot->next = pHead;
		while (pPivot->next && pPivot->next->next){
			if (pPivot->next->val == pPivot->next->next->val){
				while (pPivot->next->next && pPivot->next->val == pPivot->next->next->val){
					pPivot->next = pPivot->next->next;
				}
				pPivot->next = pPivot->next->next;
			}else 
				pPivot = pPivot->next;
		}
		return dummy.next;
	}
};