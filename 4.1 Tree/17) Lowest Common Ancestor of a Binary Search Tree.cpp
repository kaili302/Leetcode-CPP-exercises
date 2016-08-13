
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if (p->val > q->val ) std::swap(p, q);
  		if (root->val < p->val) return lowestCommonAncestor(root->right, p, q);
  		if (root->val > q->val) return  lowestCommonAncestor(root->left, p, q);
  		return root;
    }
};