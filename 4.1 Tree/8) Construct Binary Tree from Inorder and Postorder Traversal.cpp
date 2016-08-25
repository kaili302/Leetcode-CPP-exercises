/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//one pass
class Solution {
private:
	vector<TreeNode*> toDelete;
	unordered_map<int, int> hashmap;
	TreeNode* newNode(int val){
		toDelete.push_back(new TreeNode(val));
		return toDelete.back();
	}

	TreeNode* buildTree(vector<int>& postorder, int posLo, int posHi, vector<int>& inorder, int inLo, int inHi) {
		if (posLo > posHi) return nullptr;
		TreeNode *root = newNode(postorder[posHi]);
		int leftSize = hashmap[postorder[posHi]] - inLo;
		root->left = buildTree(postorder, posLo, posLo + leftSize -1, inorder, inLo, inLo + leftSize -1);
		root->right = buildTree(postorder, posLo + leftSize, posHi - 1, inorder, inLo + leftSize +1, inHi);
		return root;		        
    }

public:
	~Solution(){
		for (auto &pNode : toDelete) delete pNode;
	}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for (int i = 0; i < inorder.size(); i++)
    		hashmap.insert({inorder[i], i});

    	return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};