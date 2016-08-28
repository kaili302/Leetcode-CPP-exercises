/* Given a binary tree, flatten it to a linked list in-place.
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
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
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        stack<TreeNode*> nodesStack;
        nodesStack.push(root);
        while(nodesStack.size()){
          TreeNode *pNode = nodesStack.top();
          nodesStack.pop();
          if (!pNode->left && !pNode->right){
            pNode->right = nodesStack.empty()? nullptr : nodesStack.top();
            continue;
          }
          if (pNode->right) nodesStack.push(pNode->right);
          pNode->right = pNode->left;
          pNode->left = nullptr;
          if (pNode->right) nodesStack.push(pNode->right);
          else pNode->right = nodesStack.empty()? nullptr : nodesStack.top();
        }
    }
};