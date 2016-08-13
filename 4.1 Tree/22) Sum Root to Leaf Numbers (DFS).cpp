/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number. Find the total sum of all root-to-leaf numbers.
For example,
    1
   / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Return the sum = 12 + 13 = 25.
*/

class Solution {
private:
	void sumNumbers(TreeNode *root, int sum, int &totalSum) {
        if (!root) return;
        sum = sum*10 + root->val;
        if (root->left == nullptr && root->right == nullptr)
        	totalSum += sum;
        else {
			sumNumbers(root->left, sum, totalSum);        	
			sumNumbers(root->right, sum, totalSum);
        }
    }
public:
    int sumNumbers(TreeNode *root) {
    	int totalSum = 0;
    	sumNumbers(root, 0, totalSum);
        return totalSum;
    }
};


