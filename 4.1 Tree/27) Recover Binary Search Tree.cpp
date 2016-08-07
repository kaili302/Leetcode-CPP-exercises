/**
Two elements of a binary search tree (BST) are swapped by mistake. 
Recover the tree without changing its structure.
A solution using O(n) space is pretty straight forward. 
Could you devise a constant space solution?

Inorder traveral will return values in an increasing order. So if an element is less than its previous element,the previous element is a swapped node.
*/

class Solution {
public:
    void recoverTree(TreeNode* root) {
		TreeNode *pPivot=root;
		std::stack<TreeNode*> treeStack;
		TreeNode *pPrev=nullptr;
		TreeNode *swapped1=nullptr;
		TreeNode *swapped2=nullptr;

		while(pPivot || treeStack.size()){
			if (pPivot) {
				treeStack.push_back(pPivot);
				pPivot = pPivot->left;
			}else{
				TreeNode *pCurr=treeStack.top();
				if (!pPrev) {
					pPrev = pCurr;
				}else if(pPrev->val > pCurr->val){
					if (!swapped1) {
						swapped1=pPrev;
						swapped2=pCurr;
					}else {
						swapped2=pCurr;
						break;
					}
				}
				pPrev = pCurr;
				pPivot = pCurr->right;
				treeStack.pop();
			}
		}
		std::swap(swapped1->val, swapped2->val);
    }
};