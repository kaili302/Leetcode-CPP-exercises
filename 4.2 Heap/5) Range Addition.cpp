/*
Assume you have an array of length n initialized with all 0's and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex ... endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.


public int[] getModifiedArray(int length, int[][] updates) {
}
*/

// 最开始想到用segment tree这样整个的复杂度是nlogn

// o(n)
class Solution{
private:
	static bool compareUpdates(const vector<int> &v1, const vector<int> &v2){
		return v1[0] > v2[0];
	}

public:
	vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
		//sort(updates.begin(), updates.end(), compareUpdates);

		vector<int> result(length, 0);
		for (auto &update : updates){
			result[update[0]] += update[2];
			if (update[1] + 1 < length)
				result[update[1]+1] -= update[2];
		}

		int v = 0;
		for (auto &num : result){
			v += num;
			num = v;
		}
		return result;
	}
};


struct SegTreeNode{
	SegTreeNode *left;
	SegTreeNode *right;
	int min;
	int max;
	int mid;
	int addition;
	SegTreeNode(int imin, int imax): 
		left{nullptr}, right{nullptr}, min{imin}, max{imax}, mid{(min+max)/2}, addition{0}{}
};

/*
class Solution{
private:
	SegTreeNode* buildSegmentTree(int min, int max){
		if (min > max) return nullptr;
		SegTreeNode *root = new SegTreeNode(min, max);
		if (min == max) return root;

		int mid = (min + max) / 2;
		root->left = buildSegmentTree(min, mid);
		root->right = buildSegmentTree(mid + 1, max);
		return root;
	}


	void updateTree(SegTreeNode *root, int &min, int &max, int &addition){
		if (root->min == min && root->max == max){
			root->addition += addition;
			return;
		}else if (max <= root->mid) updateTree(root->left, min, max, addition);
		else if (min > root->mid) updateTree(root->right, min, max, addition);
		else {
			updateTree(root->left, min, root->mid, addition);
			updateTree(root->right, root->mid + 1, max, addition);
		}
	}

public:
	vector<int> getModifiedArray(int length, vector<vector<int>> &updates) {
		SegTreeNode *root = buildSegmentTree(0, length - 1);
		for (auto &update : updates){
			updateTree(root, update[0], update[1], update[2]);
		}


	}


};

*/










