/*
The houses form a binary tree. If the root is robbed, its left and right can not be robbed.
*/

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


// dp solution
class Solution {
private:
	unordered_map<TreeNode*, pair<int, int>> hashmap;
public:
	int rob(TreeNode* root) {
		return rob(root, true);
	}	
	int rob(TreeNode* root, bool canRob){
		if (!root) return 0;
		if (!hashmap.count(root))
			hashmap.insert({root, {rob(root->left, true) + rob(root->right, true), root->val + rob(root->left, false) + rob(root->right, false)}});
		int skipThis = hashmap[root].first;
		int robThis = hashmap[root].second;
		if (canRob) return max(skipThis, robThis);
		else return skipThis;
	}
};