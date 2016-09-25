/*
Given an array of integers, find if the array contains any duplicates. 
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
  		// use hash set o(n) time and space
  		unordered_set<int> hashset;
  		for (auto& num : nums){
  			if (hashset.count(num)) return true;
  			hashset.insert(num);
  		}
  		return false;
    }
};


/*
Given an array of integers and an integer k, find out whether there are two distinct 
indices i and j in the array such that nums[i] = nums[j] and 
the difference between i and j is at most k.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;
        for (int i = 0; i < nums.size(); i++){
            if (hashmap.count(nums[i])) {
                if (abs(i - hashmap[nums[i]]) <= k) return true;
                hashmap[nums[i]] = i;
            }else hashmap.emplace(nums[i], i);
        }
        return false;
    }
};


/*
Given an array of integers, find out whether there are two distinct indices i and j in 
the array such that the difference between nums[i] and nums[j] is at most t and 
the difference between i and j is at most k. Subscribe to see which companies asked this question
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
      map<int, int> treeMap;
      for (int i = 0; i < nums.size(); i++){
        if (i > k && treeMap[nums[i-k-1]] == i-k-1) 
          treeMap.erase(nums[i-k-1]);
        // now i - index in map is at most k   
        int smallestNum = nums[i] - t;
        int largestNum = nums[i] + t;
        if ((treeMap.upper_bound(smallestNum) != treeMap.end() || treeMap.count(smallestNum)) && 
             treeMap.lower_bound(largestNum) != treeMap.end())
          return true;
        if (treeMap.count(nums[i])) treeMap[nums[i]] = i;
        else treeMap.emplace(nums[i], i);
      }
      return false;
    }
};





