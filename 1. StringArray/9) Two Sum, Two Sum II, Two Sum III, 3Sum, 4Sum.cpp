/** 
Given an array of integers, return indices of the two numbers such 
that they add up to a specific target.
You may assume that each input would have exactly one solution.
Example:
Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].
UPDATE (2016/2/13):
The return format had been changed to zero-based indices. Please read the above updated description carefully.

Subscribe to see which companies asked this question
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	unordered_map<int, int> numMap;
    	vector<int> result;
    	for (int i=0; i<nums.size(); i++) {
    		if(numMap.count(nums[i])>0){
    			result.push_back(numMap[nums[i]]);
    			result.push_back(i);
    			return result;
			}else numMap.insert(make_pair(target-nums[i], i));
    	}
    	return result;
    }
};

/**
Two Sum II – Input array is sorted 
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        vector<int> result;
        while (lo<hi) {
            if (nums[lo]+nums[hi] == target) {
                result.push_back(lo);
                result.push_back(hi);
                return result;
            }else if (nums[lo]+nums[hi] < target) lo++;
            else hi--;              
        }
        return result;
    }
};


/** 
LeetCode – 3Sum
 
Problem:

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++) {
            if (i>0 && nums[i] == nums[i-1]) continue;
            int lo = i+1;
            int hi = nums.size()-1; 
            while (lo<hi) {
                if (nums[lo] + nums[hi] + nums[i] < 0)  lo++;
                else if (nums[lo] + nums[hi] + nums[i] > 0) hi--;
                else {
                    result.push_back(std::vector<int>{nums[i], nums[lo], nums[hi]});
                    while (++lo<hi && nums[lo] == result.back()[1]);
                    while (--hi>lo && nums[hi] == result.back()[2]);
                }
            }            
        }
        return result;
    }
};


/** 
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size()<4) return result;
        sort(nums.begin(), nums.end());
        // a, b, c, d is the index in non-descending order
        for (int a=0; a<nums.size(); a++){
            if (a>0 && nums[a]==nums[a-1]) continue;
            for (int b=a+1; b<nums.size(); b++){
                if (b>a+1 && nums[b]==nums[b-1]) continue;
                int c=b+1;
                int d=nums.size()-1;
                while(c<d) {
                    if (nums[a]+nums[b]+nums[c]+nums[d]<target) c++;
                    else if (nums[a]+nums[b]+nums[c]+nums[d]>target) d--;
                    else {
                        result.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        while (++c<d && nums[c]==result.back()[2]);
                        while (--d>c && nums[d]==result.back()[3]);
                    }
                }
            }
        }
        return result;
    }
};