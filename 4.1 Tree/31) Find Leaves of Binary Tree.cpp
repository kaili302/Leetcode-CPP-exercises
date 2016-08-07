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
typedef std::vector<std::vector<int>> vvint_t;
class Solution {
	vvint_t findLeaves(TreeNode *root) {
		vvint_t result;
		helper(root, result);
	}

	int helper(TreeNode *root, vvint_t &result){
		if (!root) return -1;
		int leftVal=helper(root->left, result);
		int rightVal=helper(root->right, result);
		int currVal = Math.max(leftVal, rightVal)+1;
		if (result.size()<=currVal) result.push_back(std::vector<int>{});
		result[currVal].push_back(currVal);
		return currVal;
	}
}
