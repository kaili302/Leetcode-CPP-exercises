/*
Given a binary tree and a sum, find all root-to-leaf paths 
where each path's sum equals the given sum.
For example, given the below binary tree and sum = 22,
*/

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
	void pathSum(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &result) {
		if (!root) return;
		if (root->val == sum && !root->left && !root->right){
			path.push_back(root->val);
			result.push_back(path);
			path.pop_back();
			return;
		}
		path.push_back(root->val);
		pathSum(root->left, sum - root->val, path, result);
		pathSum(root->right, sum - root->val, path, result);
		path.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<int> path;
		vector<vector<int>> result;
		pathSum(root, sum, path, result);
		return result;
    }
};