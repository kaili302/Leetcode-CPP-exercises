/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/
class Solution {
public:
    bool canJump(vector<int> &nums) {
    	int furthestPosition = 0;
    	int currentPosition = 0;
    	while (currentPosition < nums.size()){
    		if (furthestPosition >= nums.size() - 1) break; 
    		if (!nums[currentPosition]) {
    			if (furthestPosition <= currentPosition) return false;
    			else currentPosition++;
    		}else{
    			furthestPosition = max(furthestPosition, nums[currentPosition] + currentPosition);
    			currentPosition++;
    		}   
    	}
    	return true;
    }
};

