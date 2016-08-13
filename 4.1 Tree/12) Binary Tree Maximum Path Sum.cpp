/*
Given a binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path does not need to go through the root.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
*/

class Solution {
private:
	int maxPathSum(TreeNode *&root, int &maxOut) {
		if (!root) return 0;
		int leftMax = maxPathSum(root->left, maxOut);
		int rightMax = maxPathSum(root->right, maxOut);
		if (leftMax<0) leftMax=0;
		if (rightMax<0) rightMax=0;
		maxOut = std::max(maxOut, leftMax+rightMax+root->val);
		return std::max(leftMax, rightMax)+root->val;
    }
public:
    int maxPathSum(TreeNode *root) {	
    	if (!root) return 0;
    	int maxSum=root->val;
    	maxPathSum(root, maxSum);
		return maxSum;
    }
};