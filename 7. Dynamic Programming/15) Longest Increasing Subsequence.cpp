/*
Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?

Credits:
Special thanks to @pbrother for adding this problem and creating all test cases.
*/

class Solution{
public:
	int lengthOfLIS(vector<int> &nums){
		if (nums.size() <= 1) return nums.size();

		// dp[i] means the minimum end number in the LIS of length i
		// 1 3 4 2, then dp[2] = 2, dp[3] = 4
		deque<int> dp;
		dp.push_back(0);
		dp.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++){
			int j = dp.size() - 1;
			if (dp[j] < nums[i]) dp.push_back(nums[i]);
			else if (dp[j] == nums[i]) continue;
			else{
				while(j > 0 && nums[i] < dp[j]) 
					j--;
				if (nums[i] == dp[j]) continue;
				else dp[j+1] = nums[i];
			}
		}
		return dp.size() - 1;
	}
};

// optimization (use binary search to update the dp[i])



class Solution{
public:
	int lengthOfLIS(vector<int> &nums){
		if (nums.size() <= 1) return nums.size();

		deque<int> dp;
		dp.push_back(0);
		dp.push_back(nums[0]);
		for (int i = 1; i < nums.size(); i++){
			if (dp.back() < nums[i]) dp.push_back(nums[i]);
			else if (dp.back() == nums[i]) continue;
			else{
				// use binary search here
				int lo = 1, hi = dp.size() - 1;
				int mid = (lo + hi)/2;
				while (lo < hi){
					if (dp[mid] == nums[i]) break;
					else if (dp[mid] > nums[i]) hi = mid;
					else lo = mid + 1;
					mid = (lo + hi)/2;
				}
				dp[mid] = nums[i];
			}
		}
		return dp.size() - 1;
	}
};