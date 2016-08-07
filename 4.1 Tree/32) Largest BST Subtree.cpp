/*
Given a binary tree, find the largest subtree which is a (BST), 
where largest means subtree with largest number of nodes in it.
*/

class Solution{
private:
    int maxBSTCount;
    TreeNode *maxSubBST;
public:
    TreeNode* largestBSTSubtree(TreeNode *root) {
        maxBSTCount=0;
        maxSubBST=nullptr;
        helper(root);
        return maxSubBST;
    }
    int helper(TreeNode *root){
        if(!root) return 0;
        int leftBSTCount = helper(root->left);
        int rightBSTCount = helper(root->right);
        if (leftBSTCount==-1 || rightBSTCount==-1) return -1;

        int currBSTCount = 1;
        if((root->left==nullptr || root->left->val < root->val) &&
           (root->right==nullptr || root->right->val > root->val)){
            currBSTCount += leftBSTCount+rightBSTCount;
        }else return -1;
        if(currBSTCount > maxBSTCount){
            maxBSTCount=currBSTCount;
            maxSubBST=root;
        }
        return currBSTCount;
    }
};