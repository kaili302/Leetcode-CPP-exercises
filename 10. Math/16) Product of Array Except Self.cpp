/*
Given an array of n integers where n > 1, nums, 
return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int leftProduct = 1;
      int rightProduct = 1;      
      vector<int> result(nums.size(), 0);

      bool foundZero = false;
      int zeroIdx = -1;
      for (int i = 0; i < nums.size(); i++){
        if (nums[i] == 0 && foundZero) 
          return result;
        else if (nums[i] == 0) {
          foundZero = true;
          zeroIdx = i;
        }else 
          rightProduct *= nums[i];
      }
    
      if (foundZero) {result[zeroIdx] = rightProduct; return result;}
      
      for (int i = 0; i < nums.size(); i++){
        rightProduct /= nums[i];
        result[i] = leftProduct * rightProduct;
        leftProduct *= nums[i];     
      }
      return result;
    }
};
