/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

class Solution{
private:
	deque<TreeNode*> toDelete;
	TreeNode* newNode(int val){
		toDelete.push_back(new TreeNode(val));
		return toDelete.back();
	}
	
	TreeNode* generateBST(vector<int> &nums, int lo, int hi){
		if (lo > hi) return nullptr;
		int mid = (lo + hi) / 2;
		TreeNode *pNode = newNode(nums[mid]);
		pNode->left = generateBST(nums, lo, mid - 1);
		pNode->right = generateBST(nums, mid + 1, hi);
		return pNode;
	}

public:
    ~Solution(){ for (auto &pNode : toDelete) delete pNode; }
	
	TreeNode* sortedArrayToBST(vector<int> &nums){
		return generateBST(nums, 0, nums.size() - 1);
	}
};

