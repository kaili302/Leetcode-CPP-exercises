class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        ListNode* pHead = &dummy;
        while (l1 || l2){
        	if (!l1 || !l2){
        		pHead->next = !l1 ? l2 : l1;
        		break;
        	}else if (l1->val < l2->val){
        		pHead->next = l1;
        		l1 = l1->next;
        	}else{
        		pHead->next = l2;
        		l2 = l2->next;
        	}
        	pHead = pHead->next;
        }
        return dummy.next;
    }
};