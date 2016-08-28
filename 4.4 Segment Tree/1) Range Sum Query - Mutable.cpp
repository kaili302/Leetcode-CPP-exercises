/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive. 
The update(i, val) function modifies nums by updating the element at index i to val.
*/

class NumArray {
private:
	/* binary indexed tree */
	vector<int> BIT;
	void updateBIT(int idx, int val){
		idx++;
		while (idx < BIT.size()){
			BIT[idx] += val;
			idx += idx&(-idx);
		}
	}


public:
    NumArray(vector<int> &nums): BIT{nums.size() + 1, 0} {
    	for (int i = 0; i < nums.size(); i++){
    		updateBIT(i, nums[i]);
    	}
    }

    void update(int i, int val) {
     	   
    }

    int sumRange(int i, int j) {
        
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);