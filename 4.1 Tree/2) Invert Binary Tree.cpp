/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
	void invertTreeHelper(TreeNode* root) {
  		if (!root) return;
  		swap(root->left, root->right);
  		invertTreeHelper(root->left);
  		invertTreeHelper(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
  		invertTreeHelper(root);
  		return root;
    }
};