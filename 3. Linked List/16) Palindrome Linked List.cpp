/**
Given a singly linked list, determine if it is a palindrome.
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
  		if (!head) return true;
  		ListNode* slow = head;
  		ListNode* fast = head->next;
  		while (fast && fast->next) {
  			fast = fast->next->next;
  			slow = slow->next;
  		}
  		ListNode* reversed = reverse(slow->next);
  		slow->next = nullptr;
  		while (reversed) {
  			if (reversed->val != head->val) return false;
  			reversed = reversed->next;
  			head = head->next;
  		}
  		return true;
    }

    ListNode* reverse(ListNode* head) {
    	if (!head) return head;
    	ListNode* curr = head->next;
    	ListNode* prev = nullptr;
    	while (curr) {
    		ListNode* tmp = curr->next;
    		curr->next = prev;
    		prev = curr;
    		curr = tmp;
    	}
    	return prev;
    }
};