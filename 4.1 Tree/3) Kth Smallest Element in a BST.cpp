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
public:
    int kthSmallest(TreeNode* root, int k) {
        // BT inorder traversal
        stack<TreeNode*> nodesStack;
        TreeNode* pNode = root;
        while(pNode || nodesStack.size()){
        	if (pNode){
        		nodesStack.push(pNode);
        		pNode = pNode->left;
        	}else{
        		TreeNode* pNodeTmp = nodesStack.top();
        		nodesStack.pop();
        		pNode = pNodeTmp->right;
        		if (--k == 0) return pNodeTmp->val;
        	}
        }
        return -1;
    }
};