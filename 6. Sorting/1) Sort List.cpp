/*
Sort a linked list in O(n log n) time using constant space complexity.
*/


// the solution is merge sort. 
// merge sort Linkedlist takes o(1) space
class Solution {
private:
	ListNode* mergeSort(ListNode *head, ListNode *end) {
		if (head == end) return head;
		ListNode *fast = head->next;
		ListNode *mid = head;
		while (fast != end && fast != end->next) {
			fast = fast->next->next;
			mid = mid->next;
		}
		ListNode * head2 = mergeSort(mid->next, end);
		mid->next = nullptr;
		ListNode * head1 = mergeSort(head, mid);
		return merge (head1, head2);
	}

	ListNode* merge (ListNode *head1, ListNode *head2) {
		ListNode dummy{0};
		ListNode *pNode = &dummy;
		while (head1 || head2) {
			if (head1 == nullptr) {
				pNode->next = head2;
				break;
			}else if (head2 == nullptr) {
				pNode->next = head1;
				break;
			}else if (head1->val < head2->val){
				pNode->next = head1;
				pNode = pNode->next;
				head1 = head1->next;
			}else {
				pNode->next = head2;
				pNode = pNode->next;
				head2 = head2->next;
			}
		}
		return dummy.next;
	}

public:
    ListNode* sortList(ListNode* head) {
        if (!head) return head;
        ListNode *end = head;
        while (end->next) end = end->next;
        return mergeSort(head, end);
    }
};