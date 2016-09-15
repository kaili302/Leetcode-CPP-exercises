/*
Given a linked list, determine if it has a cycle in it.
ans. fast slow pointer, 如果有 肯定相遇。
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
    bool hasCycle(ListNode* head) {
        if (!head) return false;

        ListNode* pSlow = head;
        ListNode* pFast = head->next;

        while (pFast && pFast->next){
        	if (pSlow == pFast) 
        		return true;
        	pSlow = pSlow->next;
            pFast = pFast->next->next;
        }	
        return false;
    }
};