/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// one pass
class Solution {
private:
	vector<TreeNode*> toDelete;
	unordered_map<int, int> hashmap;
	TreeNode* newNode(int val){
		toDelete.push_back(new TreeNode(val));
		return toDelete.back();
	}

	TreeNode* buildTree(vector<int>& preorder, int preLo, int preHi, vector<int>& inorder, int inLo, int inHi) {
		if (preLo > preHi) return nullptr;
		TreeNode* root = newNode(preorder[preLo]);
		int leftSize = hashmap[preorder[preLo]] - inLo;
		root->left = buildTree(preorder, preLo + 1, preLo + leftSize, inorder, inLo, inLo + leftSize -1);
		root->right = buildTree(preorder, preLo + leftSize + 1, preHi, inorder, inLo + leftSize +1, inHi);
		return root;		        
    }

public:
	~Solution(){
		for (auto &pNode : toDelete) delete pNode;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	for (int i = 0; i < inorder.size(); i++)
    		hashmap.insert({inorder[i], i});

    	return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};