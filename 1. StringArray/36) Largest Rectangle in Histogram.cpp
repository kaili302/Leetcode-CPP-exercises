/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is
 1, find the area of largest rectangle in the histogram.
Given heights = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int i = 0;
        stack<int> indexs;
        int maxArea = 0;
        while (i < heights.size()){
            if (indexs.empty() || heights[i] > heights[indexs.top()]) indexs.push(i++);
            else{
                int height = heights[indexs.top()];
                indexs.pop();
                int weight = indexs.empty() ? i : i - indexs.top() - 1;
                maxArea = max(maxArea, height * weight);
            }   
        }

        cout << indexs.size() << endl;

        while (indexs.size()){
            int height = heights[indexs.top()];
            indexs.pop();
            int weight = indexs.empty() ? i : i - indexs.top() - 1;
            maxArea = max(maxArea, height * weight);
        }       
        return maxArea;
    }
};
