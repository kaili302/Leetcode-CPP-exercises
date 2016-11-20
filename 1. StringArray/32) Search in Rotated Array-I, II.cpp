/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Subscribe to see which companies asked this question
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
  		int lo = 0, hi = nums.size() - 1;
  		while (lo < hi){
  			int mid = (lo + hi) / 2; 
  			if (nums[mid] == target) return mid;
  			if (nums[lo] <= nums[mid]){
  				if (target < nums[mid] && target >= nums[lo]) hi = mid - 1;
  				else lo = mid + 1;
  			}else{
  				if (target >= nums[lo] || target < nums[mid]) hi = mid - 1;
  				else lo = mid + 1;
  			}
  		}
  		return nums[lo] == target ? lo : -1;
    }
};

/*
What if duplicates are allowed?
*/

class Solution {
public:
bool search(vector<int>& nums, int target) {
  		int lo = 0, hi = nums.size() - 1;
  		while (lo < hi){
  			while (lo < hi && nums[lo] == nums[hi]) lo++;

  			int mid = (lo + hi) / 2; 
  			if (nums[mid] == target) return true;
  			if (nums[lo] <= nums[mid]){
  				if (target < nums[mid] && target >= nums[lo]) hi = mid - 1;
  				else lo = mid + 1;
  			}else{
  				if (target >= nums[lo] || target < nums[mid]) hi = mid - 1;
  				else lo = mid + 1;
  			}
  		}
  		return nums[lo] == target;
    }
};




bool search(vector<int>& nums, int target){
  int lo =0, hi = nums.size() - 1;
  while (lo < hi){
    int mid = lo + (hi - lo)/2;
    if (target == nums[mid])
      return true;
    else if (target < nums[mid]){
      if (nums[mid] > nums[hi] && target < nums[hi]) lo = mid + 1;
      else hi = mid - 1;
    }else{
      if (target > nums[hi]) hi = mid - 1;
      else lo = mid + 1;
    }
  }
  return lo == hi && nums[lo] == target;
}



