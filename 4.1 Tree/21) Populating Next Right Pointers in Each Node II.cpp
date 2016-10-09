/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {

public:
    void connect(TreeLinkNode* root) {
        if (!root) return;
        TreeLinkNode* pPrev = root;
        TreeLinkNode dummy{0};
        TreeLinkNode* pCurr = &dummy;

        while (pPrev){
          	TreeLinkNode* pTmp = nullptr;
          	while (pPrev) {
          		if (pPrev->left == nullptr && pPrev->right == nullptr) {
          			pPrev = pPrev->next;
          			continue;
          		}
          		if (pPrev->left) {
          			if (!pTmp) pTmp = pPrev->left;
          			pCurr->next = pPrev->left;
          			pCurr = pCurr->next;
          		}
          		if (pPrev->right) {
          			if (!pTmp) pTmp = pPrev->right;
          			pCurr->next = pPrev->right;
          			pCurr = pCurr->next;
          		}
				      pPrev = pPrev->next;
        	}
        	pPrev = pTmp;
        	pCurr = &dummy;
		  }
    }
};