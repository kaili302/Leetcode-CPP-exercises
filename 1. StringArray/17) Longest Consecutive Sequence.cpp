/*
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
  		unordered_set<int> hashset;
  		for (auto& num : nums)	hashset.insert(num);
  		int maxLen = 1;
  		for (auto& num : nums){
  			if (hashset.count(num)){
  				hashset.erase(num);
  				int leftLen = 0, rightLen = 0;
  				for (int i = num - 1; hashset.count(i); leftLen++, hashset.erase(i), i--);
  				for (int i = num + 1; hashset.count(i); rightLen++, hashset.erase(i), i++);
  				maxLen = max(maxLen, 1 + leftLen + rightLen);
  			}
  		}
  		return maxLen;
    }
};