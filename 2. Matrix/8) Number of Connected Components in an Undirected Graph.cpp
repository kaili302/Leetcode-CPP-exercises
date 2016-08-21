/*Given n nodes labeled from 0 to n - 1 and a list of undirected edges, write a function to find the number of connected components in an undirected graph.
Example 1: 0 	    3 | 	    | 1 — 2  4    Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
最基本的union-find. 
*/



class Solution{
private:
    int getRoot(vector<int> &items,int val){
        while(items[val] != val) {
            int tmp = items[val];
            items[val] = items[tmp];
            val = tmp;
        }
        return val;
    }

public:
    int countComponents(int n, vector<pair<int, int>> edges) {
        vector<int> items;
        for (int i = 0; i < n; i++) {
            items.push_back(i);         
        }
        int counter = n;
        for (auto &edge : edges){
            int root1 = getRoot(items, edge.first);
            int root2 = getRoot(items, edge.second);
            if (root1 != root2) {
                items[root1] = root2;
                counter--;
            }
        }
        return counter;
    }
};