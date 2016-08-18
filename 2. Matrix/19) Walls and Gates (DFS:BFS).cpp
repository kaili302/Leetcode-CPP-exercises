#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

/*
You are given a m x n 2D grid initialized with these three possible values.

-1 -    A wall or an obstacle.
0  -    A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than2147483647.
Fill each empty room with the distance to its nearest gate. 
If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
 After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4
An application of BFS. The key is to apply appropriate pruning.
*/

// dfs solution
class Solution {
private:
    const int INF = 2147483647;
    const int GATE = 0;
    const int WALL = -1;

    int HEIGHT;
    int WIDTH;
    int count;

    void visit(vector<vector<int>> &rooms, int i, int j, int distance) {
        count++;
        if (i < 0 || i >= HEIGHT || j < 0|| j >= WIDTH || distance >= rooms[i][j]) return ;
        rooms[i][j] = distance;
        visit (rooms, i-1, j, distance+1);
        visit (rooms, i+1, j, distance+1);
        visit (rooms, i, j-1, distance+1);
        visit (rooms, i, j+1, distance+1);
    }

public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        count = 0;
        if (rooms.empty()) return;

        HEIGHT = rooms.size();
        WIDTH = rooms[0].size();

        for (int i=0; i<rooms.size(); i++) {
            for (int j=0; j<rooms[0].size(); j++) {
                if (rooms[i][j]  == GATE) {
                    visit (rooms, i-1, j, 1);
                    visit (rooms, i+1, j, 1);
                    visit (rooms, i, j-1, 1);
                    visit (rooms, i, j+1, 1);
                }                               
            }
        }
        std::cout << count << "times" <<std::endl;
    }
};


// iterate solution, more concise 

class Solution {
public:
    void wallsAndGates(vector<vector<int>> &rooms) {
        if (rooms.empty()) return;

        int HE = rooms.size();
        int WI = rooms[0].size();

        vector<pair<int, int>> dirs {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for (int i = 0; i < HE; i++) {
            for (int j = 0; j < WI; j++) {
                if (rooms[i][j]) continue;

            	queue<pair<int, int>> q;
            	q.push({i, j});
            	while (!q.empty()){
            		int r = q.front().first;
            		int c = q.front().second;
            		q.pop();
            		for (auto &dir : dirs) {
            			int x = r + dir.first;
            			int y = c + dir.second;
            			if (x < 0 || x >= HE || y < 0 || y >= WI || rooms[x][y] <= rooms[r][c]+1)
            				continue;
            			rooms[x][y] = rooms[r][c] + 1;
            			q.push({x, y});
            		}
            	}
            }
        }
    }
};









