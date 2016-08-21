/* o(n^3) dfs solution */
class Solution {
private:
    const vector<pair<int, int>> dirs{{1, 0},{-1, 0},{0, 1},{0, -1}};

    int longestIncreasingPath(vector<vector<int>>& matrix, int row, int col, int HE, int WI) {
        int count = 0;
        queue<pair<int, int>> q;
        q.push({row, col});
        while (q.size()){
            count++;
            int size = q.size();
            while (size--){
                row = q.front().first;
                col = q.front().second;
                q.pop();
                for (auto &dir : dirs){
                    int x = row + dir.first, y = col + dir.second;
                    if (x < 0 || x >= HE || y < 0 || y >= WI || matrix[x][y] <= matrix[row][col])
                        continue;
                    q.push({x, y});
                }
            }
        }
        return count;
    }
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        int HE = matrix.size();
        int WI = matrix[0].size();
        int maxPath = 0;
        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                maxPath = max(maxPath, longestIncreasingPath(matrix, r, c, HE, WI));
            }
        }
        return maxPath;
    }
};

/*亲测， 上面的非常非常慢。 可想而知... 加一个辅助就ok了*/

/* o(n^3) dfs solution */
class Solution {
private:
    const vector<pair<int, int>> dirs{{1, 0},{-1, 0},{0, 1},{0, -1}};

    int longestIncreasingPath(vector<vector<int>>& matrix, int row, int col, int HE, int WI, vector<vector<int>>& sumDis) {
        int count = 0;
        queue<pair<int, int>> q;
        if (sumDis[row][col] < 1) {
            q.push({row, col});
            sumDis[row][col] = 1;
        }

        while (q.size()){
            count++;
            int size = q.size();
            while (size--){
                row = q.front().first;
                col = q.front().second;
                q.pop();
                for (auto &dir : dirs){
                    int x = row + dir.first, y = col + dir.second;
                    if (x < 0 || x >= HE || y < 0 || y >= WI || matrix[x][y] <= matrix[row][col] || sumDis[x][y] >= sumDis[row][col]+1)
                        continue;
                    //cout << matrix[x][y] <<endl;
                    sumDis[x][y] = sumDis[row][col]+1;
                    q.push({x, y});

                }
            }
        }
        return count;
    }
public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        int HE = matrix.size();
        int WI = matrix[0].size();
        int maxPath = 0;
        vector<vector<int>> sumDis(HE, vector<int>(WI, 0));

        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                maxPath = max(maxPath, longestIncreasingPath(matrix, r, c, HE, WI, sumDis));
            }
        }
        return maxPath;
    }
};

// 上面的辅助明显有bug, 
/*
1 2 3 4
8 7 6 5
9 10 11 12
确实Ok 但是反过来就不行了*/


class Solution {
private:
    const vector<pair<int, int>> dirs{{1, 0},{-1, 0},{0, 1},{0, -1}};

    int longestIncreasingPath(vector<vector<int>> &matrix, int row, int col, int HE, int WI, vector<vector<int>> &maxPathVal) {

        /* if maxPathVal[row][col] is already calculated */
        if (maxPathVal[row][col]) return; 

        maxPathVal[row][col] = 1;
        for (auto &dir : dirs){
            int x = row + dir.firat, y = col + dir.second;
            if (x < 0 || x >= HE || y < 0 || y >= WI || matrix[row][col] >= matrix[x][y])
                continue;
            maxPathVal[row][col] = max(maxPathVal[row][col], longestIncreasingPath(matrix, x, y, HE, WI, maxPathVal) + 1);
        }
        return maxPathVal[row][col];
    }   

public:
    int longestIncreasingPath(vector<vector<int>> &matrix) {
        if (matrix.empty()) return 0;
        int HE = matrix.size();
        int WI = matrix[0].size();
        int maxPath = 0;

        vector<vector<int>> maxPathVal(HE, vector<int>(WI, 0));

        for (int r = 0; r < HE; r++){
            for (int c = 0; c < WI; c++){
                maxPath = max(maxPath, longestIncreasingPath(matrix, r, c, HE, WI, maxPathVal));
            }
        }
        return maxPath;
    }

};










