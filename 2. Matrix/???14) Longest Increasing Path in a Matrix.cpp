/* o(n^4) dfs solution */
class Solution {
private:
    void longestIncreasingPath(vector<vector<int>>& matrix, vector<pair<int, int>> &dirs, int r, int c, int HE, int WI, int pathLen, int &maxGlobal) {
        if (pathLen > maxGlobal) 
            maxGlobal = pathLen;
        for (auto &dir : dirs) {
            int x = r + dir.first, y = c + dir.second;
            if (x < 0 || x >= HE || y < 0 || y >= WI || matrix[x][y] == INT_MIN || matrix[x][y] <= matrix[r][c])
                continue;
            longestIncreasingPath(matrix, dirs, x, y, HE, WI, pathLen + 1, maxGlobal);
        }       
    }

public:
    // dfs solution
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;

        int HE = matrix.size();
        int WI = matrix[0].size();

        int maxGlobal = 1;

        vector<pair<int, int>> dirs{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (int r = 0; r < HE; r++) {
            for (int c = 0; c < WI; c++) {
                longestIncreasingPath(matrix, dirs, r, c, HE, WI, 1, maxGlobal);
            }
        }
        return maxGlobal;
    }
};


