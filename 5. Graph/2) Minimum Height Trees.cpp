/*
For a undirected graph with tree characteristics, we can choose any node as the root. 
The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called 
minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.

Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges 
(each edge is a pair of labels).

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Example 1:

Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]

        0
        |
        1
       / \
      2   3
return [1]

Example 2:

Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]

     0  1  2
      \ | /
        3
        |
        4
        |
        5
return [3, 4]
*/


class Solution{
    bool isLeaf(unordered_set<int>& node){ return node.size() == 1; }
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return {0};
        vector<unordered_set<int>> graph(n, unordered_set<int>{});
        for (auto& edge : edges){
            graph[edge.first].insert(edge.second);
            graph[edge.second].insert(edge.first);
        }
    
        queue<int> leaves;
        for (int i = 0; i < n; i++)
            if (isLeaf(graph[i])) leaves.push(i); 
        while(leaves.size() && n > 2){
            int size = leaves.size();
            n -= size;
            while(size--){
                int leaf = leaves.front();
                leaves.pop();    
                int parent = *(graph[leaf].begin());
                graph[parent].erase(leaf);
                if (isLeaf(graph[parent])) leaves.push(parent);
            }
        }
        if (leaves.size() == 1) return {leaves.front()};
        return {leaves.front(), leaves.back()};
    }
};