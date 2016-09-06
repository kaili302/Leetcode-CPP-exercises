/*
The houses form a binary tree. If the root is robbed, its left and right can not be robbed.
*/

/*time limit*/
class Solution{
private:
	int rob(TreeNode *root, bool canRobNode) {
		if (root == nullptr) return 0;
		if (canRobNode) 
			return max (root->val + rob(root->left, false) + rob(root->right, false), rob(root->left, true) + rob(root->right, true));
		else 
			return rob(root->left, true) + rob(root->right, true)
	}
public:
 	int rob(TreeNode *root) {

 		return max(rob(root, true), rob(root, false));
 	}
};

/* OK */
class Solution{
private:
	pair<int, int> robHelper(TreeNode *root) {
		if (!root) return {0, 0};
		pair<int, int> left = robHelper(root->left);
		pair<int, int> right = robHelper(root->right);
		
		pair<int, int> result;
		// first is when root is selected
		result.first = root->val + left.second + right.second;
		// second is when not
		result.second = max(left.first, left.second) + max(right.first, right.second);
		return result;
	}
public:
 	int rob(TreeNode *root) {
 		pair<int, int> result = robHelper(root);
 		return max(result.first, result.second);
 	}
};

