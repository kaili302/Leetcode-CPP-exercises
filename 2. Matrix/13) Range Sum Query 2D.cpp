/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.
Example:
Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:
The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/


// use binary indexed tree
class NumArray {
private:
	vector<int> BIT;
	vector<int> nums;

	int getLowBit (int num) { return num & (-num); }
    
	void addToBIT(int idx, int val) {
		idx++;
		while (idx < BIT.size()) {
			BIT[idx] += val;
			idx += getLowBit(idx);
		}
	}

	int getSum(int idx){
		idx++;
		int sum = 0;
		while (idx >= 1){
			sum += BIT[idx];
			idx -= getLowBit(idx);
		}
		return sum;
	}

public:
    NumArray(vector<int>& nums): BIT(nums.size()+1, 0) {
        this->nums = nums;
        for (int i = 0; i < nums.size(); i++){
        	addToBIT(i, nums[i]);
        }
    }

    void update(int i, int val) {
    	addToBIT(i, val - nums[i]);
    	nums[i] = val;
    }

    int sumRange(int i, int j) {
    	return getSum(j) - getSum(i-1);
    }
};


// use 2d binary indexed tree
class NumArray {
public:
    vector<vector<int>> BIT;
    vector<vector<int>>* pNums;
   
    int getLowBit (int num) { return num & (-num); }

    void updateBIT(int r, int c, int val, int HE, int WI) {
        for (int i = r + 1; i <= HE; i += getLowBit(i)) {
            for (int j = c +1; j <= WI; j += getLowBit(j)){
                BIT[i][j] += val;
            }
        }
    }

    int getSum(int r, int c){
        int sum = 0;
        for (int i = r + 1; i > 0; i -= getLowBit(i)){
            for (int j = c + 1; j > 0; j -= getLowBit(j)){
                sum += BIT[i][j];
            }
        }
        return sum;
    }

public:
    NumArray(vector<vector<int>>& nums): BIT(nums.size()+1, vector<int>(nums[0].size()+1, 0)) {
        pNums = &nums;
        int HE = nums.size(), WI = nums[0].size();
        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                updateBIT(r, c, nums[r][c], HE, WI);
            }
        }
    }

    void update(int r, int c, int val) {
    	updateBIT(r, c, val - (*pNums)[r][c], (*pNums).size(), (*pNums)[0].size());
        (*pNums)[r][c] = val;
    }

    int sumRange(int r1, int c1, int r2, int c2){
        return getSum(r2, c2) - getSum(r2, c1-1) - getSum(r1-1, c2) + getSum(r1-1, c1-1);
    }
};
