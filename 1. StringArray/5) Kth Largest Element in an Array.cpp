/** Find the kth largest element in an unsorted array. 
Note that it is the kth largest element in the sorted order, 
not the kth distinct element. 
For example, given [3,2,1,5,6,4] and k = 2, return 5.
Note: You may assume k is always valid, 1 ≤ k ≤ array's length. */
#include <algorithm>
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		/** 
		std::sort(nums.rbegin(), nums.rend());
		return nums[k-1];
		*/
		int lo = 0;
		int hi = nums.size() -1;
		int po;
		k--;
		do{
			po = partition (nums, lo, hi);
			if (po == k) return nums[k];
			else if (po < k) {
				lo = po + 1;
			}else {
				hi = po - 1;
			}
		}		
		return -1;
    }

    int partition(vector<int> &nums, int lo, int hi) {
    	/** lo < hi */
    	int i=lo;
    	int j=hi+1;
    	while (i<=j) {
    		while (nums[++i] >= nums[lo]) {
    			if (i==hi) break;
    		}
    		while (nums[--j] <= nums[lo]) {
    			if (j==lo) break;
    		}
    		if (i < j) {
    			swap(nums[i], nums[j]);
    		}else break;
    	}
    	swap(nums[j], nums[lo]);
    	return j;
    }
};