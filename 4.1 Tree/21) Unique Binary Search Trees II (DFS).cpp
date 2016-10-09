/*
Given n, generate all structurally unique BST's 
(binary search trees) that store values 1...n.
For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
*/

class Solution {
private:
	std::vector<TreeNode*> generateTrees(int start, int end) {
		std::vector<TreeNode*> trees;
		if (start > end) {
			trees.push_back(nullptr);
			return trees;
		}
		
		for (int i=start; i<=end; i++) {
			std::vector<TreeNode*> leftList = generateTrees(start, i-1);
			std::vector<TreeNode*> rightList = generateTrees(i+1, end);
			for (auto& leftNode:leftList) {
				for (auto& rightNode:rightList) {
					TreeNode* newNode = new TreeNode{i};
					newNode->left = leftNode;
					newNode->right = rightNode;
					trees.push_back(newNode);
				}
			}
		}
		return trees;
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        if (n==0) return {};
    	return generateTrees(1, n);
    }
};

