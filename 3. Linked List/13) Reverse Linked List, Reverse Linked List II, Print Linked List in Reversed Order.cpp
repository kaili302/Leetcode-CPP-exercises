/*
Reverse Linked List (Java)
*/
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
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

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example: given 1->2->3->4->5->NULL, m = 2 and n = 4, return 1->4->3->2->5->NULL.

Analysis
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
  		if (m == n || !head) return head;

  		ListNode dummy{0};
  		ListNode* pFakeHead = &dummy;
  		pFakeHead->next = head;
  		for (int i = 1; i < m; i++) {
  			pFakeHead = pFakeHead->next;
  		}

  		ListNode* prev = pFakeHead->next;
  		ListNode* curr = pFakeHead->next->next;
  		
  		for (int i = m; i < n; i++) {
  			ListNode* tmp = curr->next;
  			curr->next = prev;
  			prev = curr;
  			curr = tmp;
  		}
  		swap(pFakeHead->next, prev);
  		prev->next = curr;
  		return dummy.next;
    }
};