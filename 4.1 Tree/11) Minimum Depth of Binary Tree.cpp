/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
*/

class Solution {
public:
    int minDepth(TreeNode* root) {
		if (!root) return 0;

		std::queue<TreeNode*> treeQueue;
		treeQueue.push(root);
		int depth=1;

		while(treeQueue.size()) {
			int size = treeQueue.size();
			for (int i=0; i<size; i++){
				TreeNode *pNode = treeQueue.front();
				treeQueue.pop();
				if (pNode->left==nullptr && pNode->right==nullptr) return depth;
				if (pNode->left) treeQueue.push(pNode->left);
				if (pNode->right) treeQueue.push(pNode->right);
			}
			depth++;
		}
		return depth;
    }
};