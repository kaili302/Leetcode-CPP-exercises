/*
Given an array of integers, every element appears twice except for one. 
Find that single one.
*/

class Solution {
public:
	int singleNumber(vector<int> &nums) {
		int missingNum = 0;
		for (auto& num : nums){
			missingNum ^= num;
		}
		return missingNum;
	}
};

