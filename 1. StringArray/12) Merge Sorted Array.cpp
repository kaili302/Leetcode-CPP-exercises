/*
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. 
The number of elements initialized in nums1 and nums2 are m and n respectively.
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k1 = m - 1;
		int k2 = n - 1;
		for (int i = m + n - 1; i >= 0; i--){
			if (k1 == -1)
				nums1[i] = nums2[k2--];
			else if (k2 == -1)
				nums1[i] = nums1[k1--];
			else if (nums2[k2] > nums1[k1])
				nums1[i] = nums2[k2--];
			else 
				nums1[i] = nums1[k1--];
		}
    }
};
