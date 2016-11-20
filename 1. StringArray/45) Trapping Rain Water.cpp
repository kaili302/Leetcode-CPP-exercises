/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.
For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/

class Solution {
public:
    int trap(vector<int>& height) {
  		int maxHeight = 0;
  		vector<int> waters(height.size(), 0);
  		for (int i = 0; i < height.size(); i++){
  			if (height[i] > maxHeight)
  				maxHeight = height[i];
  			else
  				waters[i] = maxHeight - height[i];
  		}      
  		maxHeight = 0;
  		int totalWater = 0;
  		for (int i = height.size() - 1; i >= 0; i--){
  			if (height[i] > maxHeight){
  				waters[i] = 0;
  				maxHeight = height[i];
  			}else{
  				waters[i] = min(waters[i], maxHeight - height[i]);
			}
  			totalWater += waters[i];
  		}
  		return totalWater;
    }
};