/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example,
Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?
*/


class Solution {
public:
    int missingNumber(vector<int>& nums) {
		long total = 0;
		for (auto& num : nums) 
			total += num;      
		return (1 + nums.size()) * nums.size() / 2 - total;
    }
};



/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.
Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n^2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
  		sort(nums.begin(), nums.end());      
  		for (int i = 1; i < nums.size(); i++)
  			if (nums[i] == nums[i-1]) return nums[i];
  		return -1;
    }
};



/*
First Missing Positive 

Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
*/
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        nums.push_back(-1);
        for (int i = 0; i < nums.size(); i++){
            while (nums[i] >= 0 & nums[i] < nums.size() && nums[i] != i && nums[i] != nums[nums[i]])
                swap(nums[i], nums[nums[i]]);
        }
        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != i) return i;
        return nums.size();
    }
};

