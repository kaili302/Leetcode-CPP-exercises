/*
A 2d grid map of m rows and n columns is initially filled with water.
We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions
to operate, count the number of islands after each addLand operation. An island is surrounded by water and 
is formed byconnecting adjacent lands horizontally or vertically.  You may assume all four edges of the grid are all surrounded by
water.
*/
/* use union find */
class Solution{
private:
	vector<int> ufArray;
	int HE;
	int WI;
	const vector<pair<int, int>> dirs{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

	int get1DIdx(pair<int, int> position){
		return position.first * WI + position.second;
	}

	int get1DRoot(int idx){
		while (ufArray[idx] != idx){
			int tmp = ufArray[idx];
			ufArray[idx] = ufArray[tmp];
			idx = tmp;
		}
		return idx;
	}

	void union1DRoot(int pos1, int pos2){
		ufArray[get1DRoot(pos1)] = pos2;
	}

	void initUFArray(){
		for (int i = 0; i < HE * WI; i++){
			ufArray.push_back(i);
		}
	}


public:
	vector<int> numIslands(int m, int n, vector<vector<int>>& positions){
		if (positions.empty()) return {0};

		vector<int> result;
		int countIslands = 0;

		// init union find array
		HE = m; WI = n;
		initUFArray();
		vector<vector<int>> board(HE, vector<int>(WI, 0));

		for (auto &position : positions){
			int row = position[0], col = position[1];
			if (board[row][col]){
				result.push_back(countIslands);
				continue;
			}

			board[row][col] = 1;
			unordered_set<int> roots;
			for (auto &dir : dirs){
				int x = row + dir.first, y = col + dir.second;
				if (x < 0 || x >= HE || y < 0 || y >= WI || board[x][y] == 0)
					continue;
				roots.insert(get1DRoot(get1DIdx({x, y})));
			}

			if (roots.empty()) countIslands++;
			else{
				countIslands -= roots.size() -1;
			}
			result.push_back(countIslands);
			unordered_set<int>::iterator it;
			for ( it = roots.begin(); it != roots.end(); it++){
				union1DRoot(get1DIdx({row, col}), *it);
			}
			cout << "cIS: " << countIslands << endl;

			for (auto &row : board){
				for (auto &num : row) cout << num <<" ";
				cout << endl;
			}

		}
		return result;
	}
};


