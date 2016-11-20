/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;
		int mid = (lo + hi) / 2;

        while (lo <= hi){	
        	if (nums[mid] == target) break;
        	else if (nums[mid] < target) lo = mid + 1;
        	else hi = mid - 1;
        	mid = (lo + hi) / 2;
        }
        if (lo > hi) return {-1, -1};
     	
     	while (nums[lo] != target) lo++;
     	while (nums[hi] != target) hi--;
     	return {lo, hi};
    }
};