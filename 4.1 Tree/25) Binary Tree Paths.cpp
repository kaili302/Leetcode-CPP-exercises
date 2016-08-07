/*
Given a binary tree, return all root-to-leaf paths.
For example, given the following binary tree:
   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:
["1->2->5", "1->3"]
*/
class Solution {
private:
	void binaryTreePaths(TreeNode *root, std::vector<std::string> &result, std::ostringstream oss) {
    	if (!root) return;
    	if (root->left==nullptr && root->right==nullptr) 
    	{
    		result.push_back(oss.str()+std::to_string(root->val));
    	}else {
    		oss << std::to_string(root->val) << "->";
    		binaryTreePaths(root->left, result, oss);
    		binaryTreePaths(root->right, result, oss);
    	}
    }

public:
    std::vector<string> binaryTreePaths(TreeNode* root) {
		std::vector<std::string> result;
		binaryTreePaths(root, result, std::ostringstream());		        
    }
};