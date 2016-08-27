/*
Median is the middle value in an ordered integer list. 
If the size of the list is even, there is no middle value. 
So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
*/

class MedianFinder{
private:
	priority_queue<int, vector<int>, less<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;

public:
	void addNum(int val){
		maxHeap.push(val);
		minHeap.push(maxHeap.top());
		maxHeap.pop();
		if (minHeap.size() > maxHeap.size() + 1) {
			maxHeap.push(minHeap.top());
			minHeap.pop();
		}
	}

	double findMedian(){
		if (maxHeap.size() == minHeap.size())
			return (maxHeap.top() + minHeap.top()) / 2.0;
		return minHeap.top();
	}
};
