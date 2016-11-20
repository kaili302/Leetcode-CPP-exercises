struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

void createLevelLinkedList(TreeNode* pNode, int level, vector<list<TreeNode>>& ret){
	if (!pNode) return;
	while (ret.size() <= level)
		ret.push_back({});
	ret[level].push_back(pNode);
	createLevelLinkedList(pNode->left, level + 1, ret);
	createLevelLinkedList(pNode->right, level + 1, ret);
}

vector<list<TreeNode>> createLevelLinkedList(TreeNode* pRoot){
	vector<list<TreeNode>> ret;
	createLevelLinkedList(pRoot, 0, ret);
	return ret;
}

