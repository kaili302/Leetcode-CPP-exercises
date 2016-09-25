/*
Given a sorted array and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.
You may assume no duplicates in the array.
Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
  		int lo = 0, hi = nums.size() - 1; 
  		while (lo < hi){
  			int mid = (lo + hi) / 2;
  			if (nums[mid] == target) return mid;
  			else if (nums[mid] < target) lo = mid + 1;
  			else hi = mid - 1;
  		}

  		return nums[lo] >= target ? lo : lo + 1;
    }
};