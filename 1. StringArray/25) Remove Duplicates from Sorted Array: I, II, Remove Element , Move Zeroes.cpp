/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) return nums.size();
		int k = 0;
		for (int i = 1; i < nums.size(); i++){
			if (nums[i] != nums[k]) {
				nums[++k] = nums[i];
			}
		}
		return k + 1;
    }
};

/*
What if duplicates are allowed at most twice?
For example, Given sorted array nums = [1,1,1,2,2,3],
Your function should return length = 5,  [1, 1, 2, 2, 3]
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 2) return nums.size();
		int k = 1;
		for (int i = 2; i < nums.size(); i++){
			if (nums[i] == nums[k] && nums[k] == nums[k-1]) continue;
			else nums[++k] = nums[i];
		}
		return k + 1;
    }
};

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

Example:
Given input array nums = [3,2,2,3], val = 3

Your function should return length = 2, with the first two elements of nums being 2.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
		int k = -1;
		for (int i = 0; i < nums.size(); i++){
			if (nums[i] != val) nums[++k] = nums[i];
		}
		return k + 1;
    }
};


/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < nums.size(); i++){
        	if (nums[i]) nums[++k] = nums[i];
        }
        while (++k < nums.size()) nums[k] = 0;
    }
};


