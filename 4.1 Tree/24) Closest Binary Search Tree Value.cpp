/*
Given a non-empty binary search tree and a target value, 
find the value in the BST that is closest to the target.
*/

class Solution {
public:
  int closestValue(TreeNode *root, double target) {
    TreeNode *pNode = root;
    TreeNode *pBigPrev = nullptr;
    while(pNode) {
      if (pNode->val > target) {
        pBigPrev = pNode;
        // target is smaller than the smallest node in tree
        if (!pNode->left)
          return pNode->val;
        else pNode = pNode->left;
      }else if (pNode->val < target) {
        // target is bigger than the largest node in (sub)tree
        if (!pNode->right) {
          if (pBigPrev) 
            return ((pBigPrev->val - target) < (target - pNode->val)? pBigPrev->val: pNode->val);
          else 
            return pNode->val;
        }
        pNode = pNode->right;
      }else return pNode->val;
    }
    return 0;
  }
};




class Solution{
public:
  int closestValue(TreeNode* pRoot, int val){
    TreeNode* pCurr = pRoot;
    TreeNode* pBigPrev = nullptr;

    while (pCurr){
      if (pCurr->val == val) 
        return val;
      else if (val < pCurr->val){
        if (!pCurr->left) return pCurr->val;
        else {
          pBigPrev = pCurr;
          pCurr = pCurr->left;
        }
      }else{
        if (!pCurr->right) 
          return pBigPrev ? (val - pCurr->val < pBigPrev->val - val ? pCurr->val : pBigPrev->val) : pCurr->val;
        pCurr = pCurr->right;
      }
    }
    return 0;
  }
};