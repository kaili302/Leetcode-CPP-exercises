/*
Given a non-empty array of integers, return the k most frequent elements.

For example,
Given [1,1,1,2,2,3] and k = 2, return [1,2].

Note: 
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Subscribe to see which companies asked this question
*/


class cmp{
public:
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2)const{
		return p1.second > p2.second;
	}
};
// 注意 除了 minHeap,其实也可以用 bucket sort 的, 就是记录 frequence 的 min, max 做个 bucket.
// 这样 o(n)搞定, 而且本身 space 也是 o(n) 所以可能更好
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int, int> hashmap;
    	for (auto& num : nums){
    		if (!hashmap.count(num)) hashmap.insert({num, 1});
    		else hashmap[num]++;
    	}
    	typedef priority_queue<pair<int, int>, deque<pair<int, int>> ,cmp> MinHeap_t;
    	MinHeap_t minHeap;
    	for (auto it = hashmap.begin(); it != hashmap.end(); it++){
    		if (minHeap.size() < k){
    			minHeap.push(*it);
    		}else{
    			if (minHeap.top().second < it->second){
    				minHeap.pop();
    				minHeap.push(*it);
    			}
    		}    				
    	}
    	vector<int> ret;
    	while (minHeap.size()){
    		ret.push_back(minHeap.top().first);
    		minHeap.pop();
    	}
    	return ret;
    }
};
