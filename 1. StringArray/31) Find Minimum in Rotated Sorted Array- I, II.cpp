/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
  		int lo = 0, hi = nums.size() - 1;
  		while (lo < hi) {
  			int mid = (lo + hi) / 2;
  			if (mid == lo) return min(nums[lo], nums[hi]);
  			else if (nums[mid] > nums[hi]) lo = mid + 1;
  			else if (nums[mid] < nums[lo]) hi = mid;
  			else return nums[lo];
  		}
  		return nums[lo];
    }
};


/*
Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array may contain duplicates.
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
  		int lo = 0, hi = nums.size() - 1;
  		while (lo < hi) {
  			while (lo < hi && nums[lo] == nums[hi]) lo++;
  			int mid = (lo + hi) / 2;
  			if (mid == lo) return min(nums[lo], nums[hi]);
  			else if (nums[mid] > nums[hi]) lo = mid + 1;
  			else if (nums[mid] < nums[lo]) hi = mid;
  			else return nums[lo];
  		}
  		return nums[lo];
    }
};
