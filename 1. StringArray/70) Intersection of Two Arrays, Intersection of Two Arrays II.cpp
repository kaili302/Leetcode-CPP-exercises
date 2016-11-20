/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> hashset;
        for (auto& num : nums1){
        	hashset.insert(num);
        }

        unordered_set<int> ret;
        for(auto& num : nums2){
        	if (hashset.count(num))
        		ret.insert(num);
        }
        return {ret.begin(), ret.end()};
    }
};

/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hashmap;
        for (auto& num : nums1){
        	if (!hashmap.count(num)) 
        		hashmap.insert({num, 0});
        	hashmap[num]++;
        }

        vector<int> ret;
        for(auto& num : nums2){
        	if (hashmap.count(num)){
        		if (--hashmap[num] == 0)
        			hashmap.erase(num);
        		ret.push_back(num);
        	}
        }
        return ret;
    }
};