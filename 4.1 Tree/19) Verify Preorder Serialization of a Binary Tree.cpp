/*
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, 
we record the node's value. If it is a null node, we record using a sentinel value such as #.
     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:
"9,3,4,#,#,1,#,#,2,#,6,#,#"
Return true

Example 2:
"1,#"
Return false

Example 3:
"9,#,#,1"
Return false
*/
using std::string;

class Solution {
    bool isValidSerialization(string &preorder, int &pivot) {
    	if (pivot >= preorder.length()) return false;
		if (preorder[pivot]=='#'){
			pivot +=2;
			return true;
		}
		// pasre number
		while (preorder[pivot]!=',') pivot++;

		pivot++;
		// parse left subtree							// pasre right subtree
		return isValidSerialization(preorder, pivot) && isValidSerialization(preorder, pivot);
    }

public:
    bool isValidSerialization(string preorder) {
    	int pivot = 0;
    	if (isValidSerialization(preorder, pivot) && pivot == preorder.size()+1)  return true;
    	return false;
    }
};