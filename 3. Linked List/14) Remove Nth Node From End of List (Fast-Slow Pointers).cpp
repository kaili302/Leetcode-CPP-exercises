/**
Given a linked list, remove the nth node from the end of list and return its head.
For example, given linked list 1->2->3->4->5 and n = 2, the result is 1->2->3->5.
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode *head, int n) {
		if (!head) return head;
		ListNode *fast=head;
		ListNode *slow=head;
		// n is smaller than size of list         
		while (n--) {
			fast=fast->next;
			if (fast==nullptr) return head->next;
		}
		while (fast->next) {
			fast=fast->next;
			slow=slow->next;
		}
		slow->next=slow->next->next;
		return head;
    }
};