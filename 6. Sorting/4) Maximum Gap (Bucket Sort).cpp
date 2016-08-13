/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
Try to solve it in linear time/space. Return 0 if the array contains less than 2 elements. 
You may assume all elements in the array are non-negative integers and fit in the 32-bit signed 
integer range.
*/

struct Bucket {
	int min;
	int max;
	bool isSet=false;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size()<2) return 0;
        
		int minNum{nums[0]}; 
		int maxNum{nums[0]};
		for (auto &num : nums) {
			minNum = min(num, minNum);
			maxNum = max(num, maxNum);
		}
		// max_Gap must be at least (A_max-A_min)/A.length+1
		int avgGap=(maxNum - minNum)/nums.size() + 1;
		Bucket buckets[nums.size()+1];
		for (auto &num: nums) {
			int index = (num-minNum)/avgGap;
			if (!buckets[index].isSet) {
				buckets[index].min = num;
				buckets[index].max = num;
				buckets[index].isSet = true;
			}else {
				buckets[index].min = std::min (buckets[index].min, num);
				buckets[index].max = std::max (buckets[index].max, num);
			}
		}

		int *pMax=nullptr;
		int maxGap=0;
		for (int i=0; i< nums.size()+1; i++){	
			if (!buckets[i].isSet) continue;
			if (pMax!=nullptr) maxGap = std::max(maxGap, buckets[i].min - *pMax);
			pMax = &(buckets[i].max);			
		}
		return maxGap;
    }
};