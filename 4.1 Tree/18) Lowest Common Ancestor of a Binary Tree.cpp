/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q) return root;

        TreeNode* left = lowestCommonAncestor(root->left, p , q);
        TreeNode* right = lowestCommonAncestor(root->right, p , q);

        if (left && right) return root;
        return left? left: right;
    }
};