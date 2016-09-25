/*
Given an array of n positive integers and a positive integer s, 
find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length of 2 under the problem constraint.
*/


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      if (nums.empty()) return 0;
      int minLen = 0;
      int left = 0;
      long currSum = 0;
      for (int i = 0; i < nums.size(); i++){
        currSum += nums[i];
        while (currSum >= s){
          if (minLen == 0) minLen = i - left + 1;
          else minLen = min(minLen, i - left + 1);
          
          currSum -= nums[left++];
          if (left == nums.size() && currSum >= s)
            return 1;
        }       
      }
      return minLen;
    }
};