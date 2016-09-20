/*
You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/


class Solution {
private:
  ListNode* createNode(int val){
    return new ListNode{val};
  }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
      int carry = 0;        
      ListNode dummy{0};
      ListNode* pHead = &dummy;
      while (l1 || l2 || carry){
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        pHead->next = createNode((v1 + v2 + carry) % 10);
        pHead = pHead->next;
        carry = (v1 + v2 + carry) / 10;
        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
      }
      return dummy.next;
    }
};


