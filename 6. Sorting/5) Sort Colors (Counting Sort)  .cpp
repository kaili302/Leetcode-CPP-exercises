/*
Given an array with n objects colored red, white or blue, 
sort them so that objects of the same color are adjacent, 
with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*/



class Solution {
public:
    void sortColors(vector<int>& nums) {
        int bucket[]{0, 0, 0};
        for (auto &color: nums) {
        	bucket[color]++;
        }

		int color = 0;
        for (int i=0; i<nums.size(); i++) {
        	while (bucket[color] == 0) color++;
        	nums[i] = color;
        	bucket[color]--;
        }
    }
};