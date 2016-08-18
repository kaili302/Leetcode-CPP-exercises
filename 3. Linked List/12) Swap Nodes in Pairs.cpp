/*
Given a linked list, swap every two adjacent nodes and return its head.
For example, given 1->2->3->4, you should return the list as 2->1->4->3.
Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
    	if(!head||!head->next) return head;
    	ListNode dummy{0};
    	dummy.next=head;
    	ListNode *pHead=&dummy;
    	ListNode *prev=head;
    	ListNode *curr=head->next;
    	while (curr) {
    		ListNode *tmp=curr->next;
    		curr->next=prev;
    		prev->next=tmp;
    		pHead->next=curr;
    		pHead=prev;
    		prev=prev->next;
    		if (!prev) break;
    		curr=prev->next;
    	}
    	return dummy.next;
    }
};