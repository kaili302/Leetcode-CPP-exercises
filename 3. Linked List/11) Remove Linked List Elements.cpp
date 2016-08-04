/** 
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
*/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
		ListNode dummy{0};
		dummy.next=head;
		ListNode *pHead=&dummy;
		while (pHead->next){
			if (pHead->next->val == val) pHead->next=pHead->next->next;
			else pHead=pHead->next;
		}
		return dummy.next;
    }
};