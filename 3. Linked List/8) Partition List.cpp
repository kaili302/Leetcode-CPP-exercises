/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example, given 1->4->3->2->5->2 and x = 3, return 1->2->2->4->3->5.
*/

class Solution{
public:
	ListNode* partition(ListNode* pRoot, int X){
		ListNode less{0};
		ListNode greater{0};
		ListNode* pLess = &less;
		ListNode* pGreater = &greater;
		while (pRoot){
			if (pRoot->val < X){
				pLess->next = pRoot;
				pLess = pLess->next;
			}else {
				pGreater->next = pRoot;
				pGreater = pGreater->next;
			}
			pRoot = pRoot->next;
		}
		pGreater->next = nullptr;
		pLess->next = greater.next;

		return less.next;
	}
};