/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges 
(each edge is a pair of nodes), check if these edges form a valid tree.

Analysis

This problem can be converted to finding a cycle in a graph. It can be solved by using DFS (Recursion) or BFS (Queue).
*/


class Solution{
public:
  bool validTree(int n, vector<pair<int, int>> edges){
    vector<vector<int>> graph(n, {});
    for (auto& edge : edges){
      graph[edge.first].push_back(edge.second);
      graph[edge.second].push_back(edge.first);
    }

    queue<int> q;
    vector<bool> visited(n, false);
    q.push(0);
    while (q.size()){
      int depart = q.front();
      q.pop();
      if (visited[depart])
        return false;
      visited[depart] = true;
      for (auto& destin : graph[depart]){
        if (!visited[destin]) 
          q.push(destin);
      }
    }

    for (int i = 0; i < n; i++)
      if (!visited[i]) return false;
    return true;
  }
};