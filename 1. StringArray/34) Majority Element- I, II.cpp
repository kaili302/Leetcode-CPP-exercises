/*
Given an array of size n, find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
  		int majElement;
  		int count = 0;
  		for (auto& num : nums){
  			if (!count) {
  				majElement = num;
  				count++;
  			}else{
  				if (num == majElement) count++;
  				else count--;
  			}
  		}
  		return majElement;
    }
};