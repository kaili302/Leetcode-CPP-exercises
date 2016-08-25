/*
A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
For example, given three people living at (0,0), (0,4), and (2,2):
1 - 0 - 0 - 0 - 1
|   |   |   |   |
0 - 0 - 0 - 0 - 0
|   |   |   |   |
0 - 0 - 1 - 0 - 0
The point (0,2) is an ideal meeting point, as the total travel distance of 2+2+2=6 is minimal. So return 6.

ans. 想到的第一个方法就是遍历每一个点 求出每一个点到所有person的距离， 然后去和为最小值的点 时间复杂度比较高 n*n
第二个方法的话， 就是以每一个person为中心， 然后计算到每一个点的距离然后求和， 这样是m*n 相对小一些
*/
class Solution{
public:
	int minTotalDistance( std::vector<std::vector<int>> &grid) {
		assert(grid.size());
		int HEIGHT = grid.size();
		int WIDTH = grid[0].size();

		// sum distance

		std::vector<std::vector<int>> disSum;
		




	}
};
