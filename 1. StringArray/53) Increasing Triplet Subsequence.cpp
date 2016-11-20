/*
Given an unsorted array return whether an increasing 
subsequence of length 3 exists or not in the array.

Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

Examples:
Given [1, 2, 3, 4, 5],
return true.

Given [5, 4, 3, 2, 1],
return false.
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() <= 2) return false;
        int count = 1;
        for (int i = 1; i < nums.size(); i++){
        	if (nums[i] > nums[i-1]) count++;
        	else count = 1;
        	if (count == 3) return true;
        }
        return false;
    }
};


class Solution{
public:
	bool increasingTriplet(vector<int>& nums) {
		if (nums.size() <= 2) return false;
		int smallest = INT_MAX;
		int snd_smallest = INT_MAX;

		for (auto& num : nums){
			if (num <= smallest) smallest = num;
			else if (num <= snd_smallest) snd_smallest = num;
			else if (num > snd_smallest) return true;
		}
		return false;
	}
};
















