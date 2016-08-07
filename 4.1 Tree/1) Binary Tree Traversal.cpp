/**
1) Binary Tree Traversal: 
Preorder, 
Inorder, 
Postorder, 
Level Order, 
Level Order II, 
Vertical Order
**/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


//  Binary Tree Preorder Traversal
class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
		std::vector<int> result;
		std::stack<TreeNode*> treeStack;
		if (root) treeStack.push(root);
		while (!treeStack.empty()) {
			TreeNode* node =treeStack.top();
			treeStack.pop(); //destroy the pointer
			result.push_back(node->val);
			if (node->right) treeStack.push(node->right);
			if (node->left) treeStack.push(node->left);
		}
		return result;
    }
};

//Binary Tree Inorder Traversal
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
    	std::vector<int> result;
    	TreeNode *pNode=root;
    	std::stack<TreeNode*> treeStack;

    	while(pNode || !treeStack.empty()) {
    		if (pNode) {
    			treeStack.push(pNode);
    			pNode = pNode->left;
    		}else {
				result.push_back(treeStack.top()->val);
				pNode = treeStack.top()->right;
				treeStack.pop();
    		}
    	}
    	return result;
    }
};

// Postorder
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode *root) {
        std::vector<int> result;
    	std::unordered_set<TreeNode*> hashset;
    	std::stack<TreeNode*> treeStack;
    	TreeNode *pNode=root;
    	while(pNode || !treeStack.empty()) {
			if (pNode){
				treeStack.push(pNode);
				pNode=pNode->left;
			}else{
				TreeNode *&topNode=treeStack.top();
				if (hashset.count(topNode) || topNode->right==nullptr) {
					// rihgt child is null or is already iterated
					result.push_back(topNode->val);
					treeStack.pop();
				}else{
					pNode=topNode->right;
					hashset.insert(topNode);
				}
			}
    	}
    	return result;
    }
};

//Level Order
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
    	std::vector<std::vector<int>> result;	
    	std::queue<TreeNode*> myQueue;
    	if (root) myQueue.push(root);
    	while (myQueue.size()) {
    		int size=myQueue.size();
    		std::vector<int> line;
    		for (int i=0; i<size; i++){
    			TreeNode *&frontNode=myQueue.front();
    			line.push_back(frontNode->val);
    			if(frontNode->left) myQueue.push(frontNode->left);
    			if(frontNode->right) myQueue.push(frontNode->right);
    			myQueue.pop();
    		}
    		result.push_back(line);
    	}
    	return result;
    }
};

//Level Order II
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        std::vector<std::vector<int>> result;	
    	std::queue<TreeNode*> myQueue;
    	if (root) myQueue.push(root);
    	while (myQueue.size()) {
    		int size=myQueue.size();
    		std::vector<int> line;
    		for (int i=0; i<size; i++){
    			TreeNode *&frontNode=myQueue.front();
    			line.push_back(frontNode->val);
    			if(frontNode->left) myQueue.push(frontNode->left);
    			if(frontNode->right) myQueue.push(frontNode->right);
    			myQueue.pop();
    		}
    		result.push_back(line);
    	}
    	for (int i=0, j=result.size()-1; i<j; i++, j--){
    	    result[i].swap(result[j]);
    	}
    	return result;
    }
};

//Vertical Order
/*Given a binary tree, return the vertical order traversal of its nodes' values. 
(ie, from top to bottom, column by column).*/
class Solution {
private:
    std::unordered_map<int, std::vector<int>> hashmap;
public:
    std::vector<std::vector<int>>  verticalOrder(TreeNode *root) {
        verticalOrder(root, 0);
        std::vector<std::vector<int>> result;
        for (auto it=hashmap.begin(); it!=hashmap.end(); it++){
            result.push_back(it->second);
        }
        return result;
    }
    void verticalOrder(TreeNode *root, int weight){
        if (!root) return;
        if(hashmap.count(weight)) hashmap.insert(std::make_pair(weight, std::vector<int>{}));
        hashmap[weight].push_back(root->val);
        verticalOrder(root->left, weight-1);
        verticalOrder(root->right, weight+1);
    }
};


