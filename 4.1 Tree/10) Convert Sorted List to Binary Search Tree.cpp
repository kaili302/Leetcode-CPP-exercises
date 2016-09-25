/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
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
 // one pass ~~~~ nlogn
class Solution {
private:
	TreeNode* sortedListToBST(ListNode *head, int lo, int hi) {
		if (lo > hi) return nullptr;
		ListNode dummy{0};
		ListNode *pDummy = &dummy;
		pDummy->next = head;
		int mid = (lo + hi) / 2;

		for (int i = lo; i < mid; i++){
			pDummy = pDummy->next;
		}
		TreeNode *pRoot = new TreeNode(pDummy->next->val);
		pRoot->left = sortedListToBST(head, lo, mid - 1);
		pRoot->right = sortedListToBST(pDummy->next->next, mid + 1, hi);
		return pRoot;
	}

public:
    TreeNode* sortedListToBST(ListNode *head) {
    	ListNode *tmp = head;
    	int length = 0;
    	while (tmp) {
    		length++;
    		tmp = tmp->next;
    	}
        return sortedListToBST(head, 0, length - 1);
    }
};

