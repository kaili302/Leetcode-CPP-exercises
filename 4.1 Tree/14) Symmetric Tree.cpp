/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3
But the following [1,2,2,null,3,null,3] is not:
    1
   / \
  2   2
   \   \
   3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

class Solution {
private:
	bool isSymmetric(TreeNode* pLeft, TreeNode* pRight) {
		if (!pLeft && !pRight) return true;
		if (!pLeft || !pRight || (pLeft->val != pRight->val)) return false;
		return isSymmetric(pLeft->left, pRight->right) && isSymmetric(pLeft->right, pRight->left);
	}
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
};