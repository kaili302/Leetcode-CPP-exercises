/*
Find the contiguous subarray within an array 
(containing at least one number) which has the largest sum.
For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous subarray [4,−1,2,1] 
has the largest sum = 6.
*/

class Solution {
public:
	int maxSubArray(vector<int> &A) {
		if (A.empty()) return 0;

		int maxSubSum = A[0];
		int currSubSum = A[0];
		for (int i = 1; i < A.length(); i++){
			currSubSum = max(A[i], currSubSum + A[i]);
			maxSubSum = max(maxSubSum, currSubSum);
		}
		return maxSubSum;
	}
};