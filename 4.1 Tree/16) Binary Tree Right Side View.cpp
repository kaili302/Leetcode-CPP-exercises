/*
Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom. For example, given the following binary tree,
   1            <---
 /   \
2     3         <---
 \     
  5             <---
You can see [1, 3, 5].
*/

class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;
        std::queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        while (bfsQueue.size()){
        	int size =bfsQueue.size();
        	for (int i=0; i<size; i++) {
				TreeNode *pNode = bfsQueue.front();
				bfsQueue.pop();
				if (i==size-1) result.push_back(pNode->val);
				if (pNode->left) bfsQueue.push(pNode->left);
				if (pNode->right) bfsQueue.push(pNode->right);
			}
        }
        return result;
    }
};