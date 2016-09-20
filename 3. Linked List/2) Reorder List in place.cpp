/*
	Given a singly linked list L: L0→L1→ ... →Ln-1→Ln, 
	reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→...For example, given {1,2,3,4}, reorder it to {1,4,2,3}. 
*/


class Solution{
private:
  ListNode* reverseList(ListNode* pHead){
    ListNode* pCurr = pHead;
    ListNode* pPrev = nullptr;
    while (pCurr){
      ListNode* pTmp = pCurr->next;
      pCurr->next = pPrev;
      pPrev = pCurr;
      pCurr = pTmp;
    }
    return pPrev;
  }
  ListNode* mergeList(ListNode* pHead1, ListNode* pHead2){
    ListNode* swap = pHead1;
    // head1 > head2
    while (pHead2){
      ListNode* pTmp1 = pHead1->next;
      ListNode* pTmp2 = pHead2->next;
      pHead1->next = pHead2;
      pHead2->next = pTmp1;
      pHead1 = pTmp1;
      pHead2 = pTmp2;
    }
    return swap;
  }
public:
  ListNode* reorderList(ListNode* pHead){
    if (!pHead) return nullptr;
    ListNode* pSlow = pHead;
    ListNode* pFast = pHead->next;
    while (pFast && pFast->next){
      pSlow = pSlow->next;
      pFast = pFast->next->next;
    }

    // pSlow next should be cut to second list
    ListNode* pHead2 = pSlow->next;
    pSlow->next = nullptr;
    pHead2 = reverseList(pHead2);
    
    return mergeList(pHead, pHead2);
  } 
};

