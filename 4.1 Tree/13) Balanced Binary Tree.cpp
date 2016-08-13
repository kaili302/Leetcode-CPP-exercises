/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as a binary tree in which 
the depth of the two subtrees of every node never differ by more than 1.
Subscribe to see which companies asked this question
*/

class Solution {
private:
	int getDepth(TreeNode* root) {
  		if (root == nullptr) return 0;
  		int leftDepth = getDepth(root->left);	      
  		int rightDepth = getDepth(root->right);	      
  		if (leftDepth == -1 || rightDepth == -1 || abs(leftDepth-rightDepth)>1) return -1;
  		return max(leftDepth, rightDepth)+1;
    }

public:
    bool isBalanced(TreeNode* root) {
  		return getDepth(root) != -1;     
    }
};

