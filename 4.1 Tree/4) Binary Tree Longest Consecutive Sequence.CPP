/*
Given a binary tree, find the length of the longest consecutive sequence path.
The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. 
The longest consecutive path need to be from parent to child (cannot be the reverse).
*/

class Solution{
private:
    void longestConsecutive(TreeNode *pRootIn, int *pAscOut, int *pDesOut, int *pMaxOut) {
        if (!pRootIn) return;
        *pAscOut = 1; *pDesOut = 1;

        int leftAsc{0}, rightAsc{0}, leftDes{0}, rightDes{0};
        longestConsecutive(pRootIn->left, &leftAsc, &leftDes, pMaxOut);
        longestConsecutive(pRootIn->right, &rightAsc, &rightDes, pMaxOut);
        
        if (pRootIn->left) {
            // check ascending order (parentVal + 1 equals childVal )
            if (pRootIn->val + 1 == pRootIn->left->val) *pAscOut = leftAsc + 1;
            // check descending order (parentVal - 1 equals childVal)
            if (pRootIn->val - 1 == pRootIn->left->val) *pDesOut = leftDes + 1;
        }
        if (pRootIn->right){
            // check ascending order (parentVal + 1 equals childVal )
            if (pRootIn->val + 1 == pRootIn->right->val && rightAsc > leftAsc) *pAscOut = rightAsc + 1;   
            // check descending order (parentVal - 1 equals childVal)
            if (pRootIn->val - 1 == pRootIn->right->val && rightDes > leftDes) *pDesOut = rightDes + 1;
        } 

        *pMaxOut = max(*pMaxOut, *pAscOut > *pDesOut ? *pAscOut : *pDesOut);
    }

public:
    int longestConsecutive(TreeNode *root) {
        int maxLen{0}, ascLen{0}, desLen{0};
        longestConsecutive(root, &ascLen, &desLen, &maxLen);
        return maxLen;
    }
};


