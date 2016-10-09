#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <unordered_set>
using namespace std;

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/

class Solution {
private:
	int maxArea(vector<int>& hist){
		stack<int> s;
		int maxArea = 0;
		int i = 0;
		while( i < hist.size()){
			if (s.empty() || hist[i] >= hist[s.top()])	s.push(i++);
			else{
				int height = hist[s.top()];
				s.pop();
				int width = s.empty() ? i : i - s.top() - 1;
				maxArea = max(maxArea, height * width);
			}
		}
		i = s.top() + 1;
		while (s.size()){
			int height = hist[s.top()];
			s.pop();
			int width = s.empty() ? i : i - s.top() - 1;
			maxArea = max(maxArea, height * width);
		}
		return maxArea;
	}

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	if (matrix.empty()) return 0;
    	vector<int> heights(matrix[0].size(), 0);

    	int maxRecArea = 0;
    	for (auto& row : matrix){
    		for (int i = 0; i < row.size(); i++){
    			if (row[i] == '1') heights[i] += 1;
    			else heights[i] = 0;
    		}
    		maxRecArea = max(maxRecArea, maxArea(heights));
    	}
    	return maxRecArea;
    }
};





