/*
Given an array of integers, every element appears twice except for one. Find that single one.
*/

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (auto& num : nums)
        	result ^= num;
        return result;
    }
};