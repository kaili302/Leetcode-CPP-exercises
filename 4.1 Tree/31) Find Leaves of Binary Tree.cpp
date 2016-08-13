/**
Given a binary tree, collect a tree's nodes as if you were doing this: 
Collect and remove all leaves, repeat until the tree is empty.

Example:
Given binary tree

          1
         / \
        2   3
       / \     
      4   5    
Returns [4, 5, 3], [2], [1].
*/

// solution o(n^2)
class Solution {
public:
    std::vector<std::vector<int>> findLeaves(TreeNode *root) {
        std::vector<std::vector<int>> result;
        if (!root) return result;
        while(root->val!=-1) {
            result.push_back(std::vector<int>{});
            findLeaves(root, result.back());
        }
        return result;
    }


    void findLeaves(TreeNode *root, std::vector<int> &leaves){
        if (isEmpty(root)) return;
        if (isEmpty(root->left) && isEmpty(root->right)){
            leaves.push_back(root->val);
            root->val=-1;
        }else{
            findLeaves(root->left, leaves);
            findLeaves(root->right, leaves);
        }
    }

    bool isEmpty(TreeNode *root){
        return root==nullptr || root->val==-1;
    }
};


// solution o(n)
class Solution {
public:
    std::vector<std::vector<int>> findLeaves(TreeNode *root) {
        std::vector<std::vector<int>> result;
        helper(root, result);
        return result;
    }

    int helper(TreeNode *root, std::vector<std::vector<int>> &result){
        if (!root) return -1;
        int leftLevel = helper(root->left, result);
        int rightLevel = helper(root->right, result);

        int currLevel = std::max(leftLevel, rightLevel)+1;

        while (result.size()<=currLevel) result.push_back(std::vector<int>{});
        result[currLevel].push_back(root->val);
        return currLevel;
    }
};
