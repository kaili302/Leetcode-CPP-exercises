class Solution {
public:
    int countNodes(TreeNode* root) {
    	if (!root) return 0;
    	int leftNodes = countLeftNodes(root->left);
    	int rightNodes = countRightNodes(root->right);
    	if (leftNodes == rightNodes) return (1<<(leftNodes+1)) -1;
    	return countNodes(root->right) + countNodes(root->left) + 1;
    }

    int countLeftNodes(TreeNode* left){
    	int height = 0;
    	while (left) {
    		height++;
    		left = left->left;
    	}
    	return height;
    }

    int countRightNodes(TreeNode* right){
    	int height = 0;
    	while (right) {
    		height++;
    		right = right->right;
    	}
    	return height;
    }
};