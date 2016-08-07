/**
Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
*/

class Solution{
public:
    TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *pIterator=root;
        TreeNode *pNext;
        while (pIterator && pIterator->val != p->val) {
            if (pIterator->val > p->val) {
                pNext = pIterator;
                pIterator = pIterator->left;
            }else pIterator = pIterator->right;
        }
        if (pIterator == nullptr) return pIterator;
        if (pIterator->right == nullptr) return pNext;

        pIterator = pIterator->right;
        while(pIterator->left) pIterator = pIterator->left;
        return pIterator;
    }
};