/*
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
*/
class BSTIterator {
private:
	TreeNode* m_pRoot;
	std::stack<TreeNode*> m_stack;
	TreeNode* m_pCurr;
public:
    BSTIterator(TreeNode* root): m_pRoot{root} {
    	m_pCurr = root;
    	while (m_pCurr) {
    		m_stack.push(m_pCurr);
    		m_pCurr=m_pCurr->left;
    	}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !m_stack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* pNext = m_stack.top();
        int nextNum = pNext->val;
        m_stack.pop();

        m_pCurr=pNext->right;
        while (m_pCurr) {
    		m_stack.push(m_pCurr);
    		m_pCurr=m_pCurr->left;
    	}
    	return nextNum;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */