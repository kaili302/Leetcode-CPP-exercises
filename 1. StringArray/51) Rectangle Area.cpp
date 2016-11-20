/*
Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
*/

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    	int bottomEdgeHeight = max(B, F);
    	int topEdgeHeight = min(D, H);
    	int leftEdgeWidth = max (A, E);
    	int rightEdgeWidth = min(C, G);
    	int area = (C - A) * (D - B) + (G - E) * (H - F);
    	if (bottomEdgeHeight >= topEdgeHeight || leftEdgeWidth >= rightEdgeWidth)
    		return area;
    	return area - (topEdgeHeight - bottomEdgeHeight) * (rightEdgeWidth - leftEdgeWidth);
    }
};