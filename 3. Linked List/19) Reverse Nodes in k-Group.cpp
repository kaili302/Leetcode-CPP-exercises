/**
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
	// recursion
    ListNode* reverseKGroup(ListNode *head, int size, int k) {
        if (size<=1 || k>size ||k==1) return head;
        //reverse k nodes
        ListNode *curr=head->next;;
        ListNode *prev=head;
        ListNode *tmp;
        int count=1;
        while (count < size) {
        	tmp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=tmp;
            count++;
        }
        //reverse head and tail
        ListNode *tail =head;
        head->next=curr;
        head=prev;
        tail->next=reverseKGroup(curr, size-k, k);
        return head;
    }
    ListNode* reverseKGroup(ListNode *head, int k) {
    	int size=0;
    	ListNode *tmp=head;
    	while (tmp) {
    		size++;
    		tmp=tmp->next;
    	}
    	return reverseKGroup(head, size, k);
    }

    // straight forward
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *tmp=head;
        int size=0;
        while(tmp) {
            tmp = tmp->next;
            size++;
        }
        if (size<=1 || k>size ||k==1) return &(*head);
        // headPtr points to head of listnode
        ListNode tmpNode{0};
        ListNode *headPtr = &tmpNode;
        headPtr->next=head;
        ListNode *curr=head->next;;
        ListNode *prev=head;
        ListNode *result=nullptr;
        int count=1;
        while (k<=size) {
            //count nodes reversed
            tmp = curr->next;
            curr->next = prev;
            prev=curr;
            curr=tmp;
            count++;
            if (count == k) {
                if (!result) result=prev;
                headPtr->next->next=curr;
                swap(headPtr->next, prev);
                headPtr=prev;
                if (!curr) break;
                prev=curr;
                curr=curr->next;
                size -= k;
                count=1;
            }
        }
        return &(*result);
    }
};



