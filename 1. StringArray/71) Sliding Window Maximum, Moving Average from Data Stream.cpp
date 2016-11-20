/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array 
to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

For example,
Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.

Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
Therefore, return the max sliding window as [3,3,5,5,6,7].

Note: 
You may assume k is always valid, ie: 1 ≤ k ≤ input array's size for non-empty array.
*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  		if (nums.empty()) return {};
  		vector<int> ret;

  		for (int i = 0; i < nums.size(); i++){

  		}
    }
};

/*
LeetCode – Moving Average from Data Stream (Java)
 
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
*/

class Solution {
public:
    vector<int> movingAverage(vector<int>& nums, int k) {
        if (nums.empty()) return {};
        vector<int> ret;

        int sum = 0;
        for (int i = 0; i < nums.size(); i++){
            if (i < k) sum += nums[i];
            else {
                ret.push_back(sum / k);
                sum = sum - nums[i - k] + nums[i];
            }
        }
        ret.push_back(sum / k);
        return ret;
    }
};