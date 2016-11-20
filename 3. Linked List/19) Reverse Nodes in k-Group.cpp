/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

class Solution{
public:
    ListNode* reverseKGroup(ListNode* head, int size, int k) {
        if (size <= 1 || k > size || k == 1) return head;
        //reverse k nodes
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int count = 0;
        while (count++ < k) {
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        
        head->next = reverseKGroup(curr, size-k, k);
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* tmp=head;
        while (tmp) {
            size++;
            tmp = tmp->next;
        }
        return reverseKGroup(head, size, k);
    }
};
