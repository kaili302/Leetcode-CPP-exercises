/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.
Each element in the array represents your maximum jump length at that position.
Your goal is to reach the last index in the minimum number of jumps.
For example:
Given array A = [2,3,1,1,4]
The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int beforePrevMax = 0;
        int prevMax = 0;
        int currMax = 0;
        int count = 0;
        while (currMax < nums.size() - 1){
            for (int i = beforePrevMax; i <= prevMax; i++ )
                currMax = max(currMax, i + nums[i]);
            count++;
            beforePrevMax = prevMax;
            prevMax = currMax;
        }
        return count;
    }
};