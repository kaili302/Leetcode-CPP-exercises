/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/
/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3
*/


// bfs 

class Solution {
private:
    const vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void visit(vector<vector<char>>& grid, vector<vector<bool>> &visited, int r, int c, int HE, int WI){
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while (q.size()) {
            r = q.front().first;
            c = q.front().second;
            q.pop();
            for (auto &dir: dirs){
                int x = r + dir.first, y = c + dir.second;
                if (x < 0 || x >= HE || y < 0 || y >= WI || grid[x][y] == '0' || visited[x][y])
                    continue;           
                q.push({x, y});
                visited[x][y] = true;
            }
        }
    }

    void visitDFS(vector<vector<char>>& grid, vector<vector<bool>> &visited, int x, int y, int HE, int WI){
    	if (x < 0 || x >= HE || y < 0 || y >= WI || grid[x][y] == '0' || visited[x][y])
    		return;
    	visited[x][y] = true;
    	for (auto &dir: dirs){
	        int x = r + dir.first, y = c + dir.second;
	        visitDFS(grid, visited, x + dir.first, y + dir.second, HE, WI);
	    }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int HE = grid.size();
        int WI = grid[0].size();

        int counter = 0;

        vector<vector<bool>> visited(HE, vector<bool>(WI, false));

        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                if (grid[r][c] == '1' && !visited[r][c]){
                    counter++;
                    visitDFS(grid, visited, r, c, HE, WI);
                }
            }
        }

        return counter;
    }
};