/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
Note that there may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?
*/


class Solution{
public:
	int lengthOfLIS(const vector<int>& nums){
	    /* minIS[i]: the minimum right most number of IS of length i */
	    vector<int> minIS;
	    minIS.push_back(INT_MIN);

	    for (int i = 0; i < nums.size(); i++){
	        if (nums[i] > minIS.back())
	            minIS.push_back(nums[i]);
	        else{
	            int hi = minIS.size() - 1;
	            int lo = 1;
	            while (lo <= hi){
	                int mid = lo + (hi - lo) / 2;
	                if (minIS[mid] >= nums[i]) hi = mid - 1;
	                else lo = mid + 1;
	            }
	            minIS[hi+1] = nums[i];
	        }
	    }
	    return minIS.size() - 1;
	}
};