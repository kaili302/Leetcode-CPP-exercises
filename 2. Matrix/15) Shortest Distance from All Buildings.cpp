/*
you want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
You can only move up, down, left and right. You are given a 2D grid of values 0, 1 or 2, where:
Each 0 marks an empty land which you can pass by freely.
Each 1 marks a building which you cannot pass through.
Each 2 marks an obstacle which you cannot pass through.

For example, given three buildings at (0,0), (0,4), (2,2), and an obstacle at (0,2). The point (1,2) is an ideal empty land to
build a house, as the total travel distance of 3+3+1=7 is minimal. So return 7.
*/

class Solution{
private:
	const vector<pair<int, int>> dirs{{0,1},{0,-1},{1,0},{-1,0}};

	void visit (vector<vector<int>> &grid, int row, int col, int HE, int WI, vector<vector<bool>> visited, vector<vector<int>> &sumDis){
		queue<pair<int, int>>q;
		q.push({row, col});
		visited[row][col] = true;
		int countDis = 0;

		while (q.size()) {
			int size = q.size();
			countDis++;
			while (size--) {
				row = q.front().first; col = q.front().second;
				q.pop();
				for (auto &dir : dirs){
					int x = row + dir.first, y = col + dir.second;
					if (x < 0 || x >= HE || y < 0 || y >= WI || grid[x][y] == 2 || visited[x][y])
						continue;
					// visit (x, y)
					sumDis[x][y] += countDis;
					visited[x][y] = true;
					q.push({x, y});
				}
			}
		}
	}

public:
	int shortestDistance(vector<vector<int>> &grid) {
		if (grid.empty()) return 0;
		int HE = grid.size();
		int WI = grid[0].size();

		vector<vector<bool>> visited (HE, vector<bool>(WI, false));
		vector<vector<int>> sumDis (HE, vector<int>(WI, 0));

		for (int r = 0; r < HE; r++){
			for (int c =0; c < WI; c++){
				if (grid[r][c] == 1){
					// calculate distance from house (r,c) to all other houses
					visit(grid, r, c, HE, WI, visited, sumDis);
				}
			}
		}

		int minRow = -1, minCol = -1;
		int minDis;

		for (int r = 0; r < HE; r++){
			for (int c =0; c < WI; c++){
				if (grid[r][c] == 0 && (minRow < 0 || minDis > sumDis[r][c])){
					minRow = r; minCol = c; minDis = sumDis[r][c];
				}
			}
		}
		cout << "row: " << minRow << ", col: " << minCol << endl;
		return minDis;
	}
};
