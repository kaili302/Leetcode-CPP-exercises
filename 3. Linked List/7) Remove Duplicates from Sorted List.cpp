/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/

class Solution{
public:
	ListNode* deleteDuplicates(ListNode* pHead){
		ListNode dummy{0};
		dummy.next = pHead;
		pHead = &dummy;

		while (pHead->next && pHead->next->next){
			if (pHead->next->val == pHead->next->next->val)
				pHead->next = pHead->next->next;
			else
				pHead = pHead->next;
		}
		return dummy.next;
	}
};

